#include "IntakeIn.h"
#include "Subsystems/IntakeSubsystem.h"

IntakeIn::IntakeIn():
	CommandBase("IntakeIn")
{
	Requires(&Intake());
}

// Called just before this Command runs the first time
void IntakeIn::Initialize() {
	Intake().SetSpeed(1.0);
}

