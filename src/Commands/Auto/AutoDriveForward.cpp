#include <Commands/Auto/AutoDriveForward.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/Auto/KnownPaths.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/HighForwardSetpoint.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/WaitCommand.h"
#include "Commands/Intake/IntakeStop.h"
#include "Commands/Arm/IntakeDown.h"

AutoDriveForward::AutoDriveForward():
	CommandGroup("AutoDriveForward")
{
	AddSequential(new DriveAutoLines(-5, 0, 150 , 0.9));
	AddSequential(new LowSetpoint());
	AddSequential(new DriveAutoLines(-17, 0, 20, 0.6));
	AddSequential(new HighReverseSetpoint());
	AddSequential(new DriveAutoLines(0, -45));
	AddSequential(new DriveAutoLines(-2.2, 0, 20, 0.4));
	AddSequential(new WaitForPosition());
	AddSequential(new WaitCommand(0.25));
	AddSequential(new IntakeOut());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new IntakeStop());
	AddSequential(new IntakeDown());
	//AddSequential(new DriveAutoLines(10, 0));
	//switch
//	AddSequential(new DriveAutoLines(-5, 0, 100));
//	AddSequential(new HighForwardSetpoint());
//	AddSequential(new DriveAutoLines(-10, 0));
//	AddSequential(new WaitForPosition());
//	AddSequential(new DriveAutoLines(0, -90));
//	AddSequential(new DriveAutoLines(-1, 0));
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new WaitForPosition());
}
