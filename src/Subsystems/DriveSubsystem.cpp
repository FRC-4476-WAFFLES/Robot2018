#include <Subsystems/DriveSubsystem.h>
#include <Commands/Drive/OperatorTankDrive.h>
#include <Spark.h>
#include <Victor.h>
#include <SpeedController.h>
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		frc::Subsystem("DriveSubsystem"),
		left1(drive_left1),
		left2(drive_left2),
		left3(drive_left3),
		right1(drive_right1),
		right2(drive_right2),
		right3(drive_right3),
		left(left1, left2, left3),

		specialturnsolenoid(solenoid_extend, solenoid_retract),
		specialturnmotor(drive_lift_turn),

		right(right1, right2, right3),
		drive_base(left, right),
		gyro()

{

}

void DriveSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperatorTankDrive());
}

void DriveSubsystem::drive(float left, float right) {
	drive_base.TankDrive(left, right, false);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

