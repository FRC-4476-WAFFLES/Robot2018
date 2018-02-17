#include <Commands/Auto/AutoScoreSwitchFromCenter.h>
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/WaitCommand.h"
#include "Commands/Arm/WaitForPosition.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Intake/IntakeStop.h"

AutoScoreSwitchFromCenter::AutoScoreSwitchFromCenter() {
	SetTimeout(15.0);
	AddSequential(new SwitchState(new DriveAuto("drive and turn Left toward switch"), new DriveAuto("drive and turn Right toward switch")));
	AddSequential(new LowSetpoint());
	AddSequential(new WaitForPosition());
	AddSequential(new IntakeOut());
	AddSequential(new WaitCommand(3.0));
	AddSequential(new IntakeStop());


}
