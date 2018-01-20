#include "IntakeStop.h"

IntakeStop::IntakeStop() :
	CommandBase("IntakeStop")
{
	Requires(&Intake());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IntakeStop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeStop::Execute() {
	Intake().SetIntakeSpeed(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeStop::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeStop::Interrupted() {

}
