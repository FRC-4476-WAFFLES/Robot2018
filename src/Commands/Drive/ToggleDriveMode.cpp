#include "Commands/Drive/ToggleDriveMode.h"

ToggleDriveMode::ToggleDriveMode():
	CommandBase("ToggleDriveMode")
{
	//Requires(&Drive());

}

// Called just before this Command runs the first time
void ToggleDriveMode::Initialize() {
	Drive().drive_toggle != Drive().drive_toggle;
}

// Called repeatedly when this Command is scheduled to run
void ToggleDriveMode::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDriveMode::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleDriveMode::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleDriveMode::Interrupted() {

}
