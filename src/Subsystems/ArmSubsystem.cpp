#include "ArmSubsystem.h"
#include <SmartDashboard/SmartDashboard.h>
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../OI.h"
#include "PIDPreferences.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_motor(ARM_TILT),
		arm_motor_slave(ARM_TILT_SLAVE),
		wrist_motor(INTAKE_TILT)
		//left_intake_solenoid(INTAKE_SOLENOID_EXTEND_1, INTAKE_SOLENOID_RETRACT_1),
		//right_intake_solenoid(INTAKE_SOLENOID_EXTEND_2, INTAKE_SOLENOID_RETRACT_2)
{
	// Don't use PID until a button is pressed
	PIDJoystick = false;

	//---------------------arm pid-----------------------//
	arm_motor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	AddChild(&arm_motor);
	arm_motor_slave.SetInverted(true);
	arm_motor_slave.Follow(arm_motor);
	wrist_motor.SetInverted(true);
	wrist_motor.SetSensorPhase(true);

	//--------------------wrist pid----------------------//
	wrist_motor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10);
	AddChild(&wrist_motor);
}

// Runs when the robot's operating mode changes
void ArmSubsystem::ModeChange() {
}

// Apply all of the changes and send the commands to the motors.
void ArmSubsystem::Periodic() {
	//UpdatePID("wrist", wrist_motor, 0.0, 0.0, 0.0, 0.0);

	if(CommandBase::oi().left.GetRawButton(10)) {
		wrist_motor.SetSelectedSensorPosition(0, 0, 0);
	}

	double arm_joy = CommandBase::oi().ArmFudge();
	double wrist_joy = CommandBase::oi().WristFudge();

	double current_arm = arm_motor.GetSelectedSensorPosition(0);
	double current_wrist = wrist_motor.GetSelectedSensorPosition(0);

	if(PIDJoystick) {
		// Arm fudge
		if(fabs(arm_joy) > 0.1) {
			NextArmPosition = current_arm + arm_joy;
		}

		// Wrist fudge
		if(fabs(wrist_joy) > 0.1) {
			NextWristPosition = current_wrist + wrist_joy;
		}

		// Go to the target position
		arm_motor.Set(ControlMode::Position, NextArmPosition);
		wrist_motor.Set(ControlMode::Position, NextWristPosition);

	} else {
		// Only fudge works when in manual mode.
		arm_motor.Set(ControlMode::PercentOutput, arm_joy);
		wrist_motor.Set(ControlMode::PercentOutput, wrist_joy);
	}

}

void ArmSubsystem::Prints() {
	double current_arm = arm_motor.GetSelectedSensorPosition(0);
	double current_wrist = wrist_motor.GetSelectedSensorPosition(0);

	// Print out useful info
	{
		SmartDashboard::PutNumber("Arm/Arm/Encoder", current_arm);
		SmartDashboard::PutNumber("Arm/Arm/Target", NextArmPosition);
		SmartDashboard::PutNumber("Arm/Arm/Output", arm_motor.GetMotorOutputPercent());

		SmartDashboard::PutNumber("Arm/Wrist/Encoder", current_wrist);
		SmartDashboard::PutNumber("Arm/Wrist/Target", NextWristPosition);
		SmartDashboard::PutNumber("Arm/Wrist/Output", wrist_motor.GetMotorOutputPercent());

		SmartDashboard::PutBoolean("Arm/UseEncoder", PIDJoystick);
	}
}

// set true if the sensor should be used
void ArmSubsystem::SetUseEncoder(bool useEncoder) {
	PIDJoystick = useEncoder;
	PIDModeEnabled = useEncoder;
}

// set the intake open/closed
void ArmSubsystem::SetClamp(bool shouldClamp) {
//	if(shouldClamp) {
//		left_intake_solenoid.Set(DoubleSolenoid::kForward);
//		right_intake_solenoid.Set(DoubleSolenoid::kForward);
//	} else {
//		left_intake_solenoid.Set(DoubleSolenoid::kReverse);
//		right_intake_solenoid.Set(DoubleSolenoid::kReverse);
//	}
}

// set target
void ArmSubsystem::SeekTo(float armPosition, float wristPosition) {
	NextArmPosition = armPosition;
	NextWristPosition = wristPosition;
}
