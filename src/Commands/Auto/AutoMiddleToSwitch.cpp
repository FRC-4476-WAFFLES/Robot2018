#include "AutoMiddleToSwitch.h"

#include "Commands/Auto/States/SwitchState.h"
#include "Commands/Intake/IntakeIn.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Arm/ToggleGrab.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/WaitCommand.h"

class ScoreLeft: public CommandGroup {
public:
	ScoreLeft():
		CommandGroup("ScoreLeft")
	{
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(1, 0));
		AddSequential(new DriveAutoLines(0, -25));
		AddSequential(new DriveAutoLines(8, 0));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
		AddSequential(new DriveAutoLines(-8, 0));
		AddSequential(new DriveAutoLines(0, 25));
		AddSequential(new IntakeDown());
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(3.9, 0));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
		AddSequential(new DriveAutoLines(-3.9, 0));
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(1, 0));
		AddSequential(new DriveAutoLines(0, -28));
		AddSequential(new DriveAutoLines(7.8, 0));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
	}
};

class ScoreRight: public CommandGroup {
public:
	ScoreRight():
		CommandGroup("ScoreRight")
	{
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(1, 0));
		AddSequential(new DriveAutoLines(0, 25));
		AddSequential(new DriveAutoLines(7.5, 0));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
		AddSequential(new DriveAutoLines(-7, 0));
		AddSequential(new DriveAutoLines(0, -25));
		AddSequential(new IntakeDown());
		AddSequential(new IntakeIn());
		AddSequential(new DriveAutoLines(3.5, 0));
		AddSequential(new ToggleGrab());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
		AddSequential(new DriveAutoLines(-3.5, 0));
		AddSequential(new LowSetpoint());
		AddSequential(new LowSetpoint());
		AddSequential(new DriveAutoLines(1, 0));
		AddSequential(new DriveAutoLines(0, 28));
		AddSequential(new DriveAutoLines(7, 0, 30));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());
	}
};

AutoMiddleToSwitch::AutoMiddleToSwitch():
	CommandGroup("AutoMiddleToSwitch")
{
	AddSequential(new SwitchState(new ScoreLeft(), new ScoreRight()));
}
