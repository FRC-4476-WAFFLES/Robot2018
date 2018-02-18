#include <Commands/Auto/AutoScoreScaleFromCenter.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/WaitCommand.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"
#include "PathFinder.h"

AutoScoreScaleFromCenter::AutoScoreScaleFromCenter() {
	SetTimeout(15.0);

	AddSequential(new ScaleState(new DriveAuto("drive and turn Left toward scale"), new DriveAuto("drive and turn Right toward scale")));
	AddSequential(new LowSetpoint());
	AddSequential(new WaitForPosition());
	AddSequential(new IntakeOut());
	AddSequential(new WaitCommand(3.0));
	AddSequential(new IntakeStop());


}
