#include <Subsystems/DriveSubsystem.h>
#include <Commands/Drive/OperatorTankDrive.h>
#include <Spark.h>
#include <Victor.h>
#include <SpeedController.h>
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		frc::Subsystem("DriveSubsystem"),
		left1(DRIVE_LEFT1),
		left2(DRIVE_LEFT2),
		left3(DRIVE_LEFT3),
		right1(DRIVE_RIGHT1),
		right2(DRIVE_RIGHT2),
		right3(DRIVE_RIGHT3),
		left(left1, left2, left3),
		right(right1, right2, right3),
		drive_base(left, right),
		special_turn_solenoid(DRIVE_SOLENOID_EXTEND, DRIVE_SOLENOID_RETRACT),
		special_turn_motor(DRIVE_LIFT_TURN),
		gyro()
{
		AddChild(&drive_base);
}

void DriveSubsystem::ModeChange() {
}

void DriveSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperatorTankDrive());
}

void DriveSubsystem::drive(float left, float right) {
	special_turn_solenoid.Set(DoubleSolenoid::kReverse);
	special_turn_motor.Set(ControlMode::PercentOutput, 0);
	drive_base.TankDrive(left, right, false);
}

void DriveSubsystem::special_turn(float direction){
	special_turn_solenoid.Set(DoubleSolenoid::kForward);
	special_turn_motor.Set(ControlMode::PercentOutput, direction);
	drive_base.TankDrive(0, 0, false);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

