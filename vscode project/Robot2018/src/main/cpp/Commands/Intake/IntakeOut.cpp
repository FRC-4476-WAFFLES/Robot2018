#include "IntakeOut.h"
#include "Subsystems/IntakeSubsystem.h"

IntakeOut::IntakeOut(double spd):
	CommandBase("IntakeOut")
{
	Requires(&Intake());
	speed = spd;
}

// Called just before this Command runs the first time
void IntakeOut::Initialize() {
	Intake().SetSpeed(-speed);

}
