#include "LowSetpoint.h"

LowSetpoint::LowSetpoint():
	CommandBase("LowSetpoint")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowSetpoint::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowSetpoint::Execute() {
	Arm().ScoreLowSetpoint();
}

// Make this return true when this Command no longer needs to run execute()
bool LowSetpoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LowSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowSetpoint::Interrupted() {

}
