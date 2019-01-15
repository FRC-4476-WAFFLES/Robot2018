#include <Commands/Auto/AutoDriveForward.h>
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
#include "Commands/Drive/DriveAutoTime.h"
#include "Commands/Arm/WaitForCube.h"

AutoDriveForward::AutoDriveForward():
	CommandGroup("AutoDriveForward")
{

	//testing
//	AddSequential(new IntakeDown());
//	AddSequential(new IntakeIn());
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitForCube);
	//drive forward
//	AddSequential(new WaitCommand(12.0));
//	AddSequential(new DriveAutoTime(4.0, 0.5));
	AddSequential(new DriveAutoLines(-10, 0, 20, 0.8));
//	AddSequential(new DriveAutoLines(0, 90, 0, 0.8));

	//turn
//  Scale from side
//	AddSequential(new DriveAutoLines(-5, 0, 150 , 0.9));
//	AddSequential(new LowSetpoint());
//	AddSequential(new DriveAutoLines(-17, 0, 20, 0.6));
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(0, -45));
//	AddSequential(new DriveAutoLines(-2.2, 0, 20, 0.4));
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
//	AddSequential(new IntakeDown());

//Scla From side 2 Cube
//	AddSequential(new DriveAutoLines(-11, 0, 20 , 0.7));
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(0, -20));
//	AddSequential(new DriveAutoLines(-11.5, 0, 20, 0.4));
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop()); //drop
//	AddSequential(new WaitForPosition());
//	AddSequential(new IntakeDown());
//	AddSequential(new IntakeIn());
//	AddSequential(new DriveAutoLines(0, 28));
//	AddSequential(new DriveAutoLines(2.5, 0, 20, 0.4));
//	AddSequential(new ToggleGrab());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());//pickup
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(-2.5, 0));
//	AddSequential(new DriveAutoLines(0, -20));
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop()); //drop
//	AddSequential(new IntakeDown());



	//AddSequential(new DriveAutoLines(10, 0));

//	switch right
//	AddSequential(new LowSetpoint());
//	AddSequential(new DriveAutoLines(1, 0));
//	AddSequential(new DriveAutoLines(0, 22));
//	AddSequential(new DriveAutoLines(7.5, 0));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
//	AddSequential(new DriveAutoLines(-7, 0));
//	AddSequential(new DriveAutoLines(0, -22));
//	AddSequential(new IntakeDown());
//	AddSequential(new IntakeIn());
//	AddSequential(new DriveAutoLines(4, 0));
//	AddSequential(new ToggleGrab());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
//	AddSequential(new DriveAutoLines(-4, 0));
//	AddSequential(new LowSetpoint());
//	AddSequential(new LowSetpoint());
//	AddSequential(new DriveAutoLines(1, 0));
//	AddSequential(new DriveAutoLines(0, 28));
//	AddSequential(new DriveAutoLines(7, 0));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
// switch left
//	AddSequential(new LowSetpoint());
//	AddSequential(new DriveAutoLines(1, 0));
//	AddSequential(new DriveAutoLines(0, -25));
//	AddSequential(new DriveAutoLines(8, 0));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
//	AddSequential(new DriveAutoLines(-8, 0));
//	AddSequential(new DriveAutoLines(0, 25));
//	AddSequential(new IntakeDown());
//	AddSequential(new IntakeIn());
//	AddSequential(new DriveAutoLines(4.4, 0));
//	AddSequential(new ToggleGrab());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());
//	AddSequential(new DriveAutoLines(-4.4, 0));
//	AddSequential(new LowSetpoint());
//	AddSequential(new DriveAutoLines(1, 0));
//	AddSequential(new DriveAutoLines(0, -25));
//	AddSequential(new DriveAutoLines(7.8, 0));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());

//	AddSequential(new HighForwardSetpoint());
//	AddSequential(new DriveAutoLines(-10, 0));
//	AddSequential(new WaitForPosition());
//	AddSequential(new DriveAutoLines(0, -90));
//	AddSequential(new DriveAutoLines(-1, 0));
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new WaitForPosition());

	//cross scale from right
//	AddSequential(new DriveAutoLines(-20.2, 0));
//	AddSequential(new DriveAutoLines(0, -90));
//	AddSequential(new DriveAutoLines(-18, 0));
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(0, 90));
//	AddSequential(new DriveAutoLines(-2.5, 0));
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop()); //drop
//	AddSequential(new IntakeDown());
//	AddSequential(new DriveAutoLines(0, -7));
//	AddSequential(new WaitForPosition());
//	AddSequential(new IntakeIn());
//	AddSequential(new DriveAutoLines(2.6, 0));
//	AddSequential(new ToggleGrab());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop());//pickup
//	AddSequential(new HighReverseSetpoint());
//	AddSequential(new DriveAutoLines(-2.8, 0));
//	AddSequential(new DriveAutoLines(0, 7));
//	AddSequential(new WaitForPosition());
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new IntakeOut());
//	AddSequential(new WaitCommand(0.5));
//	AddSequential(new IntakeStop()); //drop
//	AddSequential(new IntakeDown());

}
