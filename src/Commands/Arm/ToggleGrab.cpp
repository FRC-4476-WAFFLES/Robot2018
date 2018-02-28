#include "Commands/Arm/ToggleGrab.h"

ToggleGrab::ToggleGrab():
	CommandBase("ToggleGrab")
{
	Requires(&Arm());

}

// Called just before this Command runs the first time
void ToggleGrab::Initialize() {
	Arm().SetClamp(!Arm().GetClamp());
}

// Called repeatedly when this Command is scheduled to run
void ToggleGrab::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGrab::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleGrab::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGrab::Interrupted() {

}
