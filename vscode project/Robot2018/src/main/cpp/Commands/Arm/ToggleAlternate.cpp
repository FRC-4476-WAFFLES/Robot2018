#include "Commands/Arm/ToggleAlternate.h"

ToggleAlternate::ToggleAlternate():
	CommandBase("ToggleAlternate")
{
	Requires(&Arm());

}

// Called just before this Command runs the first time
void ToggleAlternate::Initialize() {
	Arm().ToggleAlternate();

}

// Called repeatedly when this Command is scheduled to run
void ToggleAlternate::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleAlternate::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleAlternate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleAlternate::Interrupted() {

}
