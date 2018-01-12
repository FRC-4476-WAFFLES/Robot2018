#include "AutoDriveForward.h"
#include "Subsystems/DriveSubsystem.h"


AutoDriveForward::AutoDriveForward():
	CommandBase("AutoDriveForward")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&drive());
}

// Called just before this Command runs the first time
void AutoDriveForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
	drive().drive(0.1, 0.1);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoDriveForward::End() {
	drive().drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward::Interrupted() {
	End();
}
