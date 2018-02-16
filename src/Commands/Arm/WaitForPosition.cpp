#include "WaitForPosition.h"
#include "Subsystems/ArmSubsystem.h"

WaitForPosition::WaitForPosition() :
		CommandBase("WaitForPosition")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WaitForPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void WaitForPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForPosition::IsFinished() {
	return Arm().WristArmSwitch == 4;
}

// Called once after isFinished returns true
void WaitForPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForPosition::Interrupted() {

}
