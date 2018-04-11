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
#include "Commands/Arm/ToggleAlternate.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/Auto/States/PositionState.h"

class ScoreLeftFromRight: public CommandGroup {
public:
	ScoreLeftFromRight():
		CommandGroup("ScoreLeftFromRight")
	{
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-20.2, 0, 20, 0.9));
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-17.5, 0, 20, 0.9));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-2.5, 0, 20, 0.4));
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(4.1, 0, 30, 0.6));
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-4.5, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -50));
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(5.5, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(-5.5, 0, 20, 0.6));
//		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 50));
//		AddSequential(new WaitForPosition());

	}
};

class ScoreRightFromRight: public CommandGroup {
public:
	ScoreRightFromRight():
		CommandGroup("ScoreRightFromRight")
	{
		//working here--------------------------------------------------------
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.9));
		AddSequential(new DriveAutoLines(0, -17));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-11.3, 0, 20, 0.5));
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeDown());//second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, 28));
		AddSequential(new WaitForPosition());
		AddSequential(new DriveAutoLines(3.4, 0, 30, 0.6));
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-3.8, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(0, -35));
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 25));
		AddSequential(new DriveAutoLines(0, 45));//CHECK THIS BEFORE MATCH
		AddSequential(new DriveAutoLines(4.8, 0, 20, 0.6));
	}
};

class ScoreRightFromLeft: public CommandGroup {
public:
	ScoreRightFromLeft():
		CommandGroup("ScoreRightFromLeft")
	{
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-20.2, 0));
		AddSequential(new DriveAutoLines(0, 90));
		AddSequential(new DriveAutoLines(-18, 0));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -90));
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(2.6, 0));
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.8, 0));
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition());
		AddSequential(new ToggleAlternate());
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 50));
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(5.5, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(-5.5, 0, 20, 0.6));
//		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -50));
//		AddSequential(new WaitForPosition());
	}
};

class ScoreLeftFromLeft: public CommandGroup {
public:
	ScoreLeftFromLeft():
		CommandGroup("ScoreLeftFromLeft")
	{
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.7));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 20));
		AddSequential(new DriveAutoLines(-11, 0, 20, 0.4));
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeOut(0.4));
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());//second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, -28));
		AddSequential(new WaitForPosition());
		AddSequential(new DriveAutoLines(2.5, 0, 20, 0.4));
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-2.5, 0));
		AddSequential(new DriveAutoLines(0, 20));
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitForPosition());
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

AutoRightToScale::AutoRightToScale():
	CommandGroup("AutoMiddleToScale")
{
	AddSequential(new PositionState(new ScaleState(new ScoreLeftFromLeft(), new ScoreRightFromLeft()), new ScaleState(new ScoreLeftFromRight(), new ScoreRightFromRight())));
}
