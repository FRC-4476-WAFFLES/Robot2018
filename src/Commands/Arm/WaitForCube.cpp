#include "WaitForCube.h"
#include "Subsystems/ArmSubsystem.h"

WaitForCube::WaitForCube() :
		CommandBase("WaitForPosition")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WaitForCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void WaitForCube::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForCube::IsFinished() {
	return Arm().hasCUBE;
}

// Called once after isFinished returns true
void WaitForCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForCube::Interrupted() {

}
