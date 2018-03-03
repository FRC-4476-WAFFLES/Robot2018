#include <Subsystems/RobotInfo.h>
#include <SmartDashboard/SmartDashboard.h>

RobotInfo::RobotInfo():
	Subsystem("RobotInfo"),
	pdp(0)
{
	position = new SendableChooser<int*>();
	position->AddObject("Right", new int(0));
	position->AddObject("Left", new int(1));
	position->AddDefault("Center", new int(2));
	SmartDashboard::PutData("Start Position", position);
}

