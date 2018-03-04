#include <Commands/Auto/AutoRightToScale.h>
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/Intake/IntakeIn.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Arm/ToggleGrab.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/WaitCommand.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/Auto/States/PositionState.h"

class ScoreLeftFromRight: public CommandGroup {
public:
	ScoreLeftFromRight():
		CommandGroup("ScoreLeftFromRight")
	{
		AddSequential(new DriveAutoLines(-20.2, 0));
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-18, 0));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(2.6, 0));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.8, 0));
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
	}
};

class ScoreRightFromRight: public CommandGroup {
public:
	ScoreRightFromRight():
		CommandGroup("ScoreRightFromRight")
	{
		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.7));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -20));
		AddSequential(new DriveAutoLines(-11, 0, 20, 0.4));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut(0.4));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeDown());//second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, 28));
		AddSequential(new DriveAutoLines(2.5, 0, 20, 0.4));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new DriveAutoLines(0, -20));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());

	}
};

class ScoreRightFromLeft: public CommandGroup {
public:
	ScoreRightFromLeft():
		CommandGroup("ScoreRightFromLeft")
	{
		AddSequential(new DriveAutoLines(-20.2, 0));
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-18, 0));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(2.6, 0));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.8, 0));
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
	}
};

class ScoreLeftFromLeft: public CommandGroup {
public:
	ScoreLeftFromLeft():
		CommandGroup("ScoreLeftFromLeft")
	{
		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.7));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 20));
		AddSequential(new DriveAutoLines(-11, 0, 20, 0.4));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut(0.4));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeDown());//second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, -28));
		AddSequential(new DriveAutoLines(2.5, 0, 20, 0.4));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new DriveAutoLines(0, 20));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());

	}
};

AutoRightToScale::AutoRightToScale():
	CommandGroup("AutoMiddleToScale")
{
	AddSequential(new PositionState(new ScaleState(new ScoreLeftFromLeft(), new ScoreRightFromLeft()), new ScaleState(new ScoreLeftFromRight(), new ScoreRightFromRight())));
}
