#include "ArmSubsystem.h"
#include <SmartDashboard/SmartDashboard.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../OI.h"
#include "Utils/PIDPreferences.h"
#include "DigitalOutput.h"
#include "IntakeSubsystem.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_motor(ARM_TILT),
		arm_motor_slave(ARM_TILT_SLAVE),
		wrist_motor(INTAKE_TILT),
		intake_solenoid(INTAKE_SOLENOID_EXTEND_1, INTAKE_SOLENOID_RETRACT_1),
		infrared_sensor(INFRARED),
		test_motor(test),
		lights(9)
{//things
	// Set initial setpoint
	PIDJoystick = true;
	NextArmPosition = 0;
	NextWristPosition = 0;

	//---------------------arm pid-----------------------//
	arm_motor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	arm_motor.SetSensorPhase(false);
	arm_motor.SetInverted(false);
	arm_motor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0);
	arm_motor.ConfigPeakCurrentLimit(30,10);
	arm_motor.ConfigPeakCurrentDuration(30,10);
	arm_motor.ConfigContinuousCurrentLimit(30,10);
	arm_motor.EnableCurrentLimit(true);
	arm_motor.ConfigPeakOutputReverse(-0.75, 10);

	AddChild(&arm_motor);
	arm_motor_slave.SetInverted(true);
	arm_motor_slave.Follow(arm_motor);

	wrist_motor.SetInverted(false);
	wrist_motor.SetSensorPhase(true);
	wrist_motor.ConfigForwardLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0);
	wrist_motor.ConfigPeakCurrentLimit(20,10);
	wrist_motor.ConfigPeakCurrentDuration(30,10);
	wrist_motor.ConfigContinuousCurrentLimit(20,10);
	wrist_motor.EnableCurrentLimit(true);


	//--------------------wrist pid----------------------//
	wrist_motor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	AddChild(&wrist_motor);
	//fix-it
	wrist_motor.ConfigSetParameter(ParamEnum::eClearPosOnLimitR, 0, 0, 0, 10);
	wrist_motor.ConfigSetParameter(ParamEnum::eClearPosOnLimitF, 1, 0, 0, 10);
	wrist_motor.ConfigSetParameter(ParamEnum::eClearPositionOnQuadIdx, 0, 0, 0, 10);
	wrist_motor.OverrideLimitSwitchesEnable(true);

	arm_motor.ConfigSetParameter(ParamEnum::eClearPosOnLimitR, 1, 0, 0, 10);
	arm_motor.ConfigSetParameter(ParamEnum::eClearPosOnLimitF, 0, 0, 0, 10);
	arm_motor.ConfigSetParameter(ParamEnum::eClearPositionOnQuadIdx, 0, 0, 0, 10);
	arm_motor.OverrideLimitSwitchesEnable(true);
	lights.EnablePWM(0.0);


}

// Runs when the robot's operating mode changes
void ArmSubsystem::ModeChange() {
	WristArmSwitch = 4;
}

// Apply all of the changes and send the commands to the motors.
void ArmSubsystem::Periodic() {
	UpdatePID("wrist", wrist_motor, 20.0, 0.0, 20.0, 0.0);
	UpdatePID("arm", arm_motor, 9.0, 0.0, 0.0, 0.0);

	current_distance_voltage = infrared_sensor.GetValue();
	if(current_distance_voltage > 1200 && current_distance_voltage < 3000){
		hasCUBE = true;
	}else{
		hasCUBE = false;
	}
	if(CommandBase::Intake().drive_outtake_code){
		SetClamp(false);
	}

	if(hasCUBE){
		lights.UpdateDutyCycle(UpdateSinglePreference("lights duty cycle", 1.0));
	}else if(CommandBase::Intake().drive_outtake_code){
		lights.UpdateDutyCycle(0.5);
	}else{
		lights.UpdateDutyCycle(0.0);
	}
//	DigitalOutput(8).Set(CommandBase::Intake().drive_outtake_code);
//	DigitalOutput(9).Set(hasCUBE);
//	if(toggled && intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone){
//		SetClamp(true);
////	}else{
////		SetClamp(false);
//	}

	if(CommandBase::oi().left.GetRawButton(10)) {
	        wrist_motor.SetSelectedSensorPosition(0, 0, 0);
	        arm_motor.SetSelectedSensorPosition(0, 0, 0);
	}

//	if(CommandBase::oi().Back){
//        arm_motor.SetSelectedSensorPosition(0, 0, 0);
//	}

	double arm_joy = CommandBase::oi().ArmFudge();
	double wrist_joy = CommandBase::oi()
	.WristFudge();

	//double current_arm = arm_motor.GetSelectedSensorPosition(0);
	//double current_wrist = wrist_motor.GetSelectedSensorPosition(0);

	if(arm_motor.GetSensorCollection().IsRevLimitSwitchClosed()){
		arm_motor.SetSelectedSensorPosition(0, 0, 0);
	}

	if(wrist_motor.GetSensorCollection().IsFwdLimitSwitchClosed()){
		wrist_motor.SetSelectedSensorPosition(0, 0, 0);
	}


	if(PIDJoystick) {

		// Go to the target position
		if(t.Get() < 0.0){
			arm_motor.Set(ControlMode::PercentOutput, 0.0);
			wrist_motor.Set(ControlMode::PercentOutput, 0.0);
		}else if(WristArmSwitch == 1){
			wrist_motor.Set(ControlMode::Position, TRAVEL_WRIST);
			arm_motor.Set(ControlMode::Position, PosWhenSeekToSet_Arm);
			if(fabs(wrist_motor.GetSelectedSensorPosition(0) - TRAVEL_WRIST) < 40){//check if on target
				WristArmSwitch = 2;
			}
		}else if(WristArmSwitch == 2){
			wrist_motor.Set(ControlMode::Position, TRAVEL_WRIST);
			arm_motor.Set(ControlMode::Position, NextArmPosition);
			float arm_pos = arm_motor.GetSelectedSensorPosition(0);
			if(fabs(arm_pos - NextArmPosition) < 20 //check if on target
					|| (arm_pos > HIGH_LEGAL_LIMIT && PosWhenSeekToSet_Arm <= HIGH_LEGAL_LIMIT && NextArmPosition > HIGH_LEGAL_LIMIT)
					|| (arm_pos < LOW_LEGAL_LIMIT && PosWhenSeekToSet_Arm >= LOW_LEGAL_LIMIT && NextArmPosition < LOW_LEGAL_LIMIT)){
					WristArmSwitch = 3;
			}
		}else if(WristArmSwitch == 3){
			arm_motor.Set(ControlMode::Position, NextArmPosition);
			wrist_motor.Set(ControlMode::Position, NextWristPosition);
			if(fabs(wrist_motor.GetSelectedSensorPosition(0) - NextWristPosition) < 20){//check if on target
					WristArmSwitch = 4;
			}
		} else {
			// Arm fudge
			if(fabs(arm_joy) > 0.1) {
				NextArmPosition =  arm_motor.GetSelectedSensorPosition(0) + arm_joy * 50.0;
			}

			// Wrist fudge
			if(fabs(wrist_joy) > 0.1) {
				if(wrist_motor.GetSelectedSensorPosition(0) > -1000.0){ //TODO use real values
					NextWristPosition = wrist_motor.GetSelectedSensorPosition(0) + wrist_joy * 50.0;
				}else{
					NextWristPosition = wrist_motor.GetSelectedSensorPosition(0) + wrist_joy * -50.0;
				}
			}

			if(outtaking){
				NextWristPosition4 = NextWristPosition + 7;
			}else{
				NextWristPosition4 = NextWristPosition;
			}

			arm_motor.Set(ControlMode::Position, NextArmPosition);
			wrist_motor.Set(ControlMode::Position, NextWristPosition4);
		}

	} else {
		// Only fudge works when in manual mode.
		arm_motor.Set(ControlMode::PercentOutput, arm_joy);
		wrist_motor.Set(ControlMode::PercentOutput, wrist_joy);
	}


}

void ArmSubsystem::Prints() {
	// Print out useful info
	SmartDashboard::PutNumber("Arm/Arm/Encoder", arm_motor.GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Arm/Arm/Target", arm_motor.GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("Arm/Arm/Output", arm_motor.GetMotorOutputPercent());

	SmartDashboard::PutBoolean("Arm Limit", arm_motor.GetSensorCollection().IsRevLimitSwitchClosed());

	SmartDashboard::PutNumber("Arm/Wrist/Encoder", wrist_motor.GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Arm/Wrist/Target", wrist_motor.GetClosedLoopTarget(0));
	SmartDashboard::PutNumber("Arm/Wrist/Output", wrist_motor.GetMotorOutputPercent());

	SmartDashboard::PutBoolean("wrist Limit", wrist_motor.GetSensorCollection().IsFwdLimitSwitchClosed());

	SmartDashboard::PutBoolean("Arm/UseEncoder", PIDJoystick);

	SmartDashboard::PutNumber("arm target", NextArmPosition);
	SmartDashboard::PutNumber("wrist target", NextWristPosition);
	SmartDashboard::PutNumber("Arm/Infrared/infrared voltage", current_distance_voltage);
	SmartDashboard::PutBoolean("/Arm/Infrared/Has Cube?", hasCUBE);
}

// set true if the sensor should be used
void ArmSubsystem::SetUseEncoder(bool useEncoder) {
	PIDJoystick = useEncoder;
	PIDModeEnabled = useEncoder;
}

// set the intake open/closed
void ArmSubsystem::SetClamp(bool shouldClamp) {
	t.Reset();
	t.Start();

	if(shouldClamp) {
		intake_solenoid.Set(DoubleSolenoid::kForward);
	} else {
		intake_solenoid.Set(DoubleSolenoid::kReverse);
	}
}

// get the intake open/closed
bool ArmSubsystem::GetClamp() {
	return intake_solenoid.Get() == DoubleSolenoid::kForward;
}

// set target
void ArmSubsystem::SeekTo(float armPosition, float wristPosition) {
	SeekTo(armPosition, wristPosition, wristPosition);
	toggled = false;
}

// set target with alternate wrist
void ArmSubsystem::SeekTo(float armPosition, float wristPosition, float alternateWristPosition) {
	PosWhenSeekToSet_Arm = arm_motor.GetSelectedSensorPosition(0);
	PosWhenSeekToSet_Wrist = wrist_motor.GetSelectedSensorPosition(0);

	NextArmPosition = armPosition;
	NextWristPosition = wristPosition;
	AlternateWristPosition = alternateWristPosition;

	if((NextArmPosition < HIGH_LEGAL_LIMIT && PosWhenSeekToSet_Arm > LOW_LEGAL_LIMIT) ||
		(NextArmPosition > LOW_LEGAL_LIMIT && PosWhenSeekToSet_Arm < HIGH_LEGAL_LIMIT))
	{
		// We need to go in first
		WristArmSwitch = 1;
	} else {
		// We can just go there
		WristArmSwitch = 4;
	}
}

void ArmSubsystem::ToggleAlternate() {
	// Swap the wrist position for the alternate wrist position

	SeekTo(NextArmPosition, AlternateWristPosition, NextWristPosition);
	toggled = true;
}

void ArmSubsystem::ResetArmEncoder() {
	arm_motor.SetSelectedSensorPosition(0, 0, 0);
}
