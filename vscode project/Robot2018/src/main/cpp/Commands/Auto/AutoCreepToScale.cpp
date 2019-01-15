#include <Commands/Auto/AutoCreepToScale.h>
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
#include "Commands/Arm/ToggleAlternate.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/Auto/States/PositionState.h"

class ScoreCreepLeftFromRight: public CommandGroup {
public:
	/////////////FIX ALL NUMBERS////////////
	ScoreCreepLeftFromRight():
		CommandGroup("ScoreCreepLeftFromRight")
	{
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-2, 0, 20, 0.5));
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-17.5, 0, 20, 0.9));
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-22.2, 0, 20, 0.9));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new WaitForPosition());
	}
};

class ScoreCreepRightFromRight: public CommandGroup {
public:
	ScoreCreepRightFromRight():
		CommandGroup("ScoreCreepRightFromRight")
	{
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.9));
		AddSequential(new DriveAutoLines(0, -17));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-11.3, 0, 20, 0.5));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeDown());//second cube
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, 28));
		AddSequential(new DriveAutoLines(3.4, 0, 30, 0.6));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-3.8, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(0, -35));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new ToggleAlternate());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 25));
		AddSequential(new DriveAutoLines(4.8, 0, 20, 0.6));
	}
};

class ScoreCreepRightFromLeft: public CommandGroup {
public:
	ScoreCreepRightFromLeft():
		CommandGroup("ScoreCreepRightFromLeft")
	{

		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-2, 0, 20, 0.5));
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-17.5, 0, 20, 0.9));
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-22.2, 0, 20, 0.9));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new WaitForPosition());
	}
};

class ScoreCreepLeftFromLeft: public CommandGroup {
public:
	ScoreCreepLeftFromLeft():
		CommandGroup("ScoreCreepLeftFromLeft")
	{
		AddSequential(new ToggleGrab());
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
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -35));
		AddSequential(new WaitForPosition());
		AddSequential(new DriveAutoLines(3, 0, 20, 0.6));

	}
};

AutoCreepToScale::AutoCreepToScale():
	CommandGroup("AutoCreepToScale")
{
	AddSequential(new PositionState(new ScaleState(new ScoreCreepLeftFromLeft(), new ScoreCreepRightFromLeft()), new ScaleState(new ScoreCreepLeftFromRight(), new ScoreCreepRightFromRight())));
}
