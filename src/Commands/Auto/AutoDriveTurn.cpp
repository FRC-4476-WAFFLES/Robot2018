#include <Commands/Auto/AutoDriveTurn.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Arm/ToggleGrab.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/Auto/KnownPaths.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/HighForwardSetpoint.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeIn.h"
#include "Commands/WaitCommand.h"
#include "Commands/Intake/IntakeStop.h"
#include "Commands/Arm/IntakeDown.h"

AutoDriveTurn::AutoDriveTurn():
	CommandGroup("AutoDriveTurn")
{
	//drive turn
	AddSequential(new DriveAutoLines(5, 0, 15, 0.8));
	AddSequential(new DriveAutoLines(0, 90));

}
