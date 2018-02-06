#include <Commands/Arm/HighForwardSetpoint.h>

HighForwardSetpoint::HighForwardSetpoint():
	CommandBase("HighSetpoint")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void HighForwardSetpoint::Initialize() {
	Arm().SetClamp(true);
	Arm().SeekTo(Arm().HIGH_FORWARD_ARM, Arm().HIGH_FORWARD_WRIST);
}

// Called repeatedly when this Command is scheduled to run
void HighForwardSetpoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool HighForwardSetpoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HighForwardSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighForwardSetpoint::Interrupted() {

}
