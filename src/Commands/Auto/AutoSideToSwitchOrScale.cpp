#include "AutoSideToSwitchOrScale.h"

#include "Commands/Auto/States/PositionState.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Commands/WaitCommand.h"

class ScoreSwitch: public CommandGroup {
public:
	ScoreSwitch():
		CommandGroup("Score Switch")
	{
		// Move wrist up
		AddSequential(new LowSetpoint());

		// Drive forward to align with side of switch
		AddSequential(new DriveAutoLines(0, 0, 15, 0.8));

		// Turn towards switch
		AddSequential(new PositionState(new DriveAutoLines(0, 90), new DriveAutoLines(0, -90))); 

		// Drive forwards to switch
		AddSequential(new WaitForPosition());
		AddSequential(new DriveAutoLines(2, 0));

		// Score
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());

		// Back up
		AddSequential(new DriveAutoLines(-2, 0));
		AddSequential(new IntakeDown());
	}
};

class ScoreScale: public CommandGroup {
public:
	ScoreScale():
		CommandGroup("Score Scale")
	{
		// Move arm up
		AddSequential(new HighReverseSetpoint());

		// Drive to the scale
		AddSequential(new PositionState(new DriveAutoLines(0, 20), new DriveAutoLines(0, -20)));
		AddSequential(new DriveAutoLines(-11.5, 0, 20, 0.4));

		// Score
		AddSequential(new WaitForPosition());
		AddSequential(new WaitCommand(0.25));
		AddSequential(new IntakeOut());
		AddSequential(new WaitCommand(0.5));
		AddSequential(new IntakeStop());

		// Move the intake back down
		AddSequential(new IntakeDown());
	}
};

AutoSideToSwitchOrScale::AutoSideToSwitchOrScale():
	CommandGroup("AutoSideToSwitchOrScale")
{
	// Unconditional drive
	AddSequential(new DriveAutoLines(-11, 0, 20, 0.7));

	AddSequential(
		new PositionState(
			new SwitchState(
				// Score on switch because we are on the same side
				new ScoreSwitch(),
				// Can't score on switch, Check if we can score on the scale instead
				new ScaleState(
					// We can score on the scale
					new ScoreScale(),
					// We can't score on anything, just drive forward
					new DriveAutoLines(-10, 0)
				)
			),
			new SwitchState(
				// Can't score on switch, Check if we can score on the scale instead
				new ScaleState(
					// We can't score on anything, just drive forward
					new DriveAutoLines(-10, 0),
					// We can score on the scale
					new ScoreScale()
				),
				// Score on switch because we are on the same side
				new ScoreSwitch()
			)
		)
	);
}
