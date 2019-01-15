#include <Commands/Auto/AutoScoreSwitchFromCenter.h>
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/WaitCommand.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"
#include "KnownPaths.h"
#include "Commands/Arm/HighReverseSetpoint.h"

AutoScoreSwitchFromCenter::AutoScoreSwitchFromCenter():
	CommandGroup("AutoScoreSwitchFromCenter")
{
	//SetTimeout(15.0);
	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(3., 0.));
//	AddSequential(new DriveAutoLines(0., 90.));
//	AddSequential(new DriveAutoLines(3., 0.));
//	AddSequential(new DriveAutoLines(0., -90.));
//	AddSequential(new DriveAutoLines(3., 0.));
	//AddSequential(new SwitchState(new DriveAuto(DriveToLeftSwitchFromCenter()), new DriveAuto(DriveToLeftSwitchFromCenter())));// second is right
//	AddSequential(new LowSetpoint());
//	AddSequential(new WaitForPosition());
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(3.0));
//	AddSequential(new IntakeStop());


}
