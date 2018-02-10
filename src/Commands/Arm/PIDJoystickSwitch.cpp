#include "Commands/Arm/PIDJoystickSwitch.h"

PIDJoystickSwitch::PIDJoystickSwitch():
	CommandBase("PIDJoystickSwitch")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PIDJoystickSwitch::Initialize() {
	Arm().SetUseEncoder(!Arm().PIDModeEnabled);
}

// Called repeatedly when this Command is scheduled to run
void PIDJoystickSwitch::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool PIDJoystickSwitch::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PIDJoystickSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDJoystickSwitch::Interrupted() {

}
