#include "Commands/Arm/LowSetpoint.h"
#include "Subsystems/IntakeSubsystem.h"

LowSetpoint::LowSetpoint():
	CommandBase("LowSetpoint")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowSetpoint::Initialize() {
	Arm().SetClamp(true);
	Arm().SeekTo(Arm().LOW_FORWARD_ARM, Arm().LOW_FORWARD_WRIST, 0);
	Arm().intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone = false;
}

// Called repeatedly when this Command is scheduled to run
void LowSetpoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LowSetpoint::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LowSetpoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowSetpoint::Interrupted() {

}
