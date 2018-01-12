#include "OperatorTankDrive.h"
#include "Subsystems/DriveSubsystem.h"

OperatorTankDrive::OperatorTankDrive():
	CommandBase("OperatorTankDrive")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drive());
}

// Called just before this Command runs the first time
void OperatorTankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OperatorTankDrive::Execute() {
	drive().drive(oi().left.GetY(), oi().right.GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool OperatorTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OperatorTankDrive::End() {
	drive().drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperatorTankDrive::Interrupted() {
	End();
}
