#include "IntakeOut.h"

IntakeOut::IntakeOut():
	CommandBase("IntakeOut")
{
	Requires(&Intake());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IntakeOut::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute() {
	Intake().SetIntakeSpeed(-1.0);
	Intake().CloseIntake();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOut::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeOut::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOut::Interrupted() {

}
