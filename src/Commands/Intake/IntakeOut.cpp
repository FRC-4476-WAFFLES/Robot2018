#include "IntakeOut.h"
#include "Subsystems/IntakeSubsystem.h"

IntakeOut::IntakeOut():
	CommandBase("IntakeOut")
{
	Requires(&Intake());
}

// Called just before this Command runs the first time
void IntakeOut::Initialize() {
	Intake().SetSpeed(-0.5);
}
