#include <Commands/Auto/AutoScoreSwitchFromSide.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/WaitCommand.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Auto/States/PositionState.h"
#include "Commands/Intake/IntakeStop.h"

AutoScoreSwitchFromSide::AutoScoreSwitchFromSide():
	CommandGroup("AutoScoreSwitchFromSide")
{
	SetTimeout(15.0);
	AddSequential(new PositionState(new SwitchState(new DriveAuto("drive and turn toward switch"),new DriveAuto("drive")), new SwitchState(new DriveAuto("drive"),new DriveAuto("drive and turn toward switch"))));
	AddSequential(new LowSetpoint());
	AddSequential(new WaitForPosition());
	AddSequential(new PositionState(new SwitchState(new IntakeOut,new WaitForPosition()), new SwitchState(new WaitForPosition(),new IntakeOut())));
	AddSequential(new WaitCommand(3.0));
	AddSequential(new IntakeStop());
}
