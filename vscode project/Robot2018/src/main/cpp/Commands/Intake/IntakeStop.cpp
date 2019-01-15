#include "IntakeStop.h"
#include "Subsystems/IntakeSubsystem.h"

IntakeStop::IntakeStop() :
	CommandBase("IntakeStop")
{
	Requires(&Intake());
}

// Called just before this Command runs the first time
void IntakeStop::Initialize() {
	Intake().SetSpeed(0.0);
}
