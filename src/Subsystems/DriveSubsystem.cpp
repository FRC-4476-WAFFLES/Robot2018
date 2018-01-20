#include <Subsystems/DriveSubsystem.h>
#include <Commands/Drive/OperatorTankDrive.h>
#include <Spark.h>
#include <Victor.h>
#include <SpeedController.h>
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		frc::Subsystem("DriveSubsystem"),
		gyro(),
		left1(drive_left1),
		left2(drive_left2),
		left3(drive_left3),
		right1(drive_right1),
		right2(drive_right2),
		right3(drive_right3),
		left(left1, left2, left3),
		right(right1, right2, right3),
		drive_base(left, right),
		special_turn_solenoid(solenoid_extend, solenoid_retract),
		special_turn_motor(drive_lift_turn)
{

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

