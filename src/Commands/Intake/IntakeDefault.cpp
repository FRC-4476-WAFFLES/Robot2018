#include "IntakeDefault.h"

IntakeDefault::IntakeDefault() :
	CommandBase("IntakeDefault")
{
	Requires(&Intake());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void IntakeDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeDefault::Execute() {
	Intake().SetIntakeSpeed(0.1);
	Intake().CloseIntake();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeDefault::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDefault::Interrupted() {

}
