#include "ArmSubsystem.h"
#include <SmartDashboard/SmartDashboard.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../OI.h"
#include "Utils/PIDPreferences.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_motor(ARM_TILT),
		arm_motor_slave(ARM_TILT_SLAVE),
		wrist_motor(INTAKE_TILT),
		intake_solenoid(INTAKE_SOLENOID_EXTEND_1, INTAKE_SOLENOID_RETRACT_1)
{
	// Don't use PID until a button is pressed
	PIDJoystick = false;

	//---------------------arm pid-----------------------//
	arm_motor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	arm_motor.SetSensorPhase(false);
	arm_motor.SetInverted(false);
	arm_motor.ConfigReverseLimitSwitchSource(LimitSwitchSource::LimitSwitchSource_FeedbackConnector, LimitSwitchNormal::LimitSwitchNormal_NormallyOpen, 0);
	arm_motor.ConfigPeakCurrentLimit(20,10);
	arm_motor.ConfigPeakCurrentDuration(30,10);
	arm_motor.ConfigContinuousCurrentLimit(20,10);
	arm_motor.EnableCurrentLimit(true);

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
}

// Runs when the robot's operating mode changes
void ArmSubsystem::ModeChange() {
}

// Apply all of the changes and send the commands to the motors.
void ArmSubsystem::Periodic() {
	UpdatePID("wrist", wrist_motor, 15.0, 0.0, 0.0, 0.0);
	UpdatePID("arm", arm_motor, 15.0, 0.0, 0.0, 0.0);

	if(CommandBase::oi().left.GetRawButton(10)) {
	        wrist_motor.SetSelectedSensorPosition(0, 0, 0);
	        arm_motor.SetSelectedSensorPosition(0, 0, 0);
	}

	double arm_joy = CommandBase::oi().ArmFudge();
	double wrist_joy = CommandBase::oi().WristFudge();

	double current_arm = arm_motor.GetSelectedSensorPosition(0);
	double current_wrist = wrist_motor.GetSelectedSensorPosition(0);


	if(PIDJoystick) {
		// Arm fudge
		/*if(fabs(arm_joy) > 0.1) {
			NextArmPosition = current_arm + arm_joy;
		}

		// Wrist fudge
		if(fabs(wrist_joy) > 0.1) {
			NextWristPosition = current_wrist + wrist_joy;
		}*/

		// Go to the target position
		/*if(WristArmSwitch == 1){
			wrist_motor.Set(ControlMode::Position, FULL_IN_WRIST);
			arm_motor.Set(ControlMode::Position, PosWhenSeekToSet_Arm);
			if(fabs(wrist_motor.GetClosedLoopError(0)) < 20){//check if on target
				WristArmSwitch = 2;
			}
		}else if(WristArmSwitch == 2){
			wrist_motor.Set(ControlMode::Position, FULL_IN_WRIST);
			arm_motor.Set(ControlMode::Position, NextArmPosition);
			if(fabs(arm_motor.GetClosedLoopError(0)) < 20){//check if on target
					WristArmSwitch = 3;
			}
		}else if(WristArmSwitch == 3){
			arm_motor.Set(ControlMode::Position, NextArmPosition);
			wrist_motor.Set(ControlMode::Position, NextWristPosition);
			if(fabs(wrist_motor.GetClosedLoopError(0)) < 20){//check if on target
					WristArmSwitch = 4;
			}
		} else {*/
		if(t.Get() > 0.5){
			arm_motor.Set(ControlMode::Position, NextArmPosition);
			wrist_motor.Set(ControlMode::Position, NextWristPosition);
		} else {
			arm_motor.Set(ControlMode::PercentOutput, 0.0);
			wrist_motor.Set(ControlMode::PercentOutput, 0.0);
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

// set target
void ArmSubsystem::SeekTo(float armPosition, float wristPosition) {
	WristArmSwitch = 4;
	PosWhenSeekToSet_Wrist = wrist_motor.GetSelectedSensorPosition(0);
	NextWristPosition = wristPosition;
	PosWhenSeekToSet_Arm = arm_motor.GetSelectedSensorPosition(0);
	NextArmPosition = armPosition;
}
