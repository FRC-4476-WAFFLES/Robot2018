#include <Subsystems/RobotInfo.h>

RobotInfo::RobotInfo():
	Subsystem("RobotInfo"),
	pdp(0)
{

	position = new SendableChooser<int*>();
	position->AddObject("Right", new int(0));
	position->AddObject("Left", new int(1));
}

