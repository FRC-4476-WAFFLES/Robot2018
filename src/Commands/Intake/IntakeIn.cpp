#include "IntakeIn.h"

IntakeIn::IntakeIn():
	CommandBase("IntakeIn")
{
	Requires(&Intake());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IntakeIn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeIn::Execute() {
	Intake().SetIntakeSpeed(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeIn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeIn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeIn::Interrupted() {

}
