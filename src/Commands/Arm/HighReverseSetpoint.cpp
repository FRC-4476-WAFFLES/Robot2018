#include <Commands/Arm/HighReverseSetpoint.h>

HighReverseSetpoint::HighReverseSetpoint():
	CommandBase("HighSetpoint")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void HighReverseSetpoint::Initialize() {
	Arm().ScoreHighReverseSetpiont();
}

// Called repeatedly when this Command is scheduled to run
void HighReverseSetpoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool HighReverseSetpoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HighReverseSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighReverseSetpoint::Interrupted() {

}
