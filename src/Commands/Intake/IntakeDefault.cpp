#include "IntakeDefault.h"
#include "Subsystems/IntakeSubsystem.h"

IntakeDefault::IntakeDefault() :
	CommandBase("IntakeDefault")
{
	Requires(&Intake());
}

// Called just before this Command runs the first time
void IntakeDefault::Initialize() {
	Intake().SetSpeed(0.1);
}
