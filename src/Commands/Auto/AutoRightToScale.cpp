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
#include "Commands/Arm/WaitForCube.h"

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
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddParallel(new DriveAutoLines(5.1, 0, 30, 0.6));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-5.5, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new WaitForPosition());
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, -50));
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(5.6, 0, 20, 0.6));
		AddSequential(new DriveAutoLines(-5.6, 0, 20, 0.6));
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
		AddSequential(new DriveAutoLines(-12, 0, 20 , 0.9));
		AddSequential(new DriveAutoLines(0, -16));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-10.4, 0, 20, 0.5));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.5));
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
		AddParallel(new DriveAutoLines(4.4, 0, 30, 0.7));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.5));//////////////////////////////////////not here anymore
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-4.8, 0, 20, 0.7));
		AddSequential(new DriveAutoLines(0, -35));
		AddSequential(new WaitForPosition());
//		AddSequential(new WaitCommand(0.5));//////////////////////////////////////
		AddSequential(new ToggleAlternate());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeIn());//3rd cube pickup
		AddSequential(new DriveAutoLines(0, 60, 20, 0.4));//CHECK THIS BEFORE MATCH
		AddParallel(new DriveAutoLines(6.1, 0, 20, 0.7));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.25));////////////////////////////////////////
		AddSequential(new IntakeStop());
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(-6.1, 0, 20, 0.7));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, -55));
		AddSequential(new WaitForPosition());// 3rd drop
		AddSequential(new WaitCommand(0.5));
		AddSequential(new ToggleAlternate());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop());
		AddSequential(new IntakeDown());

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
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new DriveAutoLines(0, 7));
		AddSequential(new WaitForPosition()); //second cube
		AddSequential(new IntakeIn());
		AddParallel(new DriveAutoLines(3.6, 0));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-3.8, 0));
		AddSequential(new DriveAutoLines(0, -7));
		AddSequential(new WaitForPosition());
		AddSequential(new ToggleAlternate());
		AddSequential(new WaitCommand(0.25));
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

		//initial left
//		AddSequential(new ToggleGrab());
//		AddSequential(new DriveAutoLines(-11, 0, 20 , 0.7));
//		AddSequential(new HighReverseSetpoint());
//		AddSequential(new DriveAutoLines(0, 20));
//		AddSequential(new DriveAutoLines(-11, 0, 20, 0.4));
//		AddSequential(new WaitForPosition());
//		AddSequential(new WaitCommand(0.25));
//		AddSequential(new IntakeOut(0.4));
//		AddSequential(new WaitCommand(0.5));
//		AddSequential(new IntakeStop()); //drop
//		AddSequential(new WaitForPosition());
//		AddSequential(new IntakeDown());//second cube
//		AddSequential(new IntakeIn());
//		AddSequential(new DriveAutoLines(0, -25));
//		AddSequential(new DriveAutoLines(2.5, 0, 20, 0.4));
//		AddSequential(new WaitForCube());
//		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.5));
//		AddSequential(new IntakeStop());//pickup
//		AddSequential(new HighReverseSetpoint());
//		AddSequential(new DriveAutoLines(-2.5, 0));
//		AddSequential(new DriveAutoLines(0, 20));
//		AddSequential(new WaitForPosition());
//		AddSequential(new ToggleAlternate());
//		AddSequential(new WaitCommand(0.25));
//		AddSequential(new IntakeOut());
//		AddSequential(new WaitCommand(0.5));
//		AddSequential(new IntakeStop()); //drop
//		AddSequential(new IntakeDown());
//		AddSequential(new IntakeIn());//3rd cube pickup
//		AddSequential(new DriveAutoLines(0, -35, 20, 0.4));
//		AddSequential(new DriveAutoLines(4.9, 0, 20, 0.7));
//		AddSequential(new WaitForCube());
//		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.25));
//		AddSequential(new IntakeStop());
//		AddSequential(new LowSetpoint());
//		AddSequential(new DriveAutoLines(4.9, 0, 20, 0.7));
//		AddSequential(new HighReverseSetpoint());
//		AddSequential(new DriveAutoLines(0, 35, 20, 0.4));
//		AddSequential(new WaitCommand(0.5));
//		AddSequential(new IntakeOut(1));
//		AddSequential(new WaitCommand(0.05));
//		AddSequential(new IntakeOut(0.3));
//		AddSequential(new WaitCommand(0.25));
//		AddSequential(new IntakeStop());
//		AddSequential(new IntakeDown());

//mirrored from right
		AddSequential(new ToggleGrab());
		AddSequential(new DriveAutoLines(-12, 0, 20 , 0.9));
		AddSequential(new DriveAutoLines(0, 17));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-10.3, 0, 20, 0.5));
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new WaitForPosition());
		AddSequential(new IntakeDown());//second cube
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(0, -31));
		AddSequential(new WaitForPosition());
		AddParallel(new DriveAutoLines(4.4, 0, 30, 0.7));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.5));//////////////////////////////////////not here anymore
		AddSequential(new IntakeStop());//pickup
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(-4.8, 0, 20, 0.7));
		AddSequential(new DriveAutoLines(0, 35));
		AddSequential(new WaitForPosition());
//		AddSequential(new WaitCommand(0.5));//////////////////////////////////////
		AddSequential(new ToggleAlternate());
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop()); //drop
		AddSequential(new IntakeDown());
		AddSequential(new ToggleGrab());
		AddSequential(new IntakeIn());//3rd cube pickup
		AddSequential(new DriveAutoLines(0, -60, 20, 0.4));//CHECK THIS BEFORE MATCH
		AddParallel(new DriveAutoLines(6.1, 0, 20, 0.7));
		AddSequential(new WaitForCube());
		AddSequential(new ToggleGrab());
//		AddSequential(new WaitCommand(0.25));////////////////////////////////////////
		AddSequential(new IntakeStop());
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(-5.1, 0, 20, 0.7));
		AddSequential(new HighReverseSetpoint());
		AddSequential(new DriveAutoLines(0, 55));
		AddSequential(new WaitForPosition());// 3rd drop
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeOut(1));
		AddSequential(new WaitCommand(0.05));
		AddSequential(new IntakeOut(0.3));
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeStop());
		AddSequential(new IntakeDown());
	}
};

AutoRightToScale::AutoRightToScale():
	CommandGroup("AutoMiddleToScale")
{
	AddSequential(new PositionState(new ScaleState(new ScoreLeftFromLeft(), new ScoreRightFromLeft()), new ScaleState(new ScoreLeftFromRight(), new ScoreRightFromRight())));
}
