#include "Commands/Arm/IntakeDown.h"
#include "Subsystems/IntakeSubsystem.h"
IntakeDown::IntakeDown():
	CommandBase("IntakeDown")
{
	Requires(&Arm());

}

// Called just before this Command runs the first time
void IntakeDown::Initialize() {
	Arm().SeekTo(Arm().INTAKE_ARM, Arm().INTAKE_WRIST, 0);
	Arm().SetClamp(false);
	Arm().intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone = true;
}

// Called repeatedly when this Command is scheduled to run
void IntakeDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void IntakeDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeDown::Interrupted() {

}
