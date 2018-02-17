#pragma once
#include <Commands/Subsystem.h>
#include <PowerDistributionPanel.h>
#include <SmartDashboard/SendableChooser.h>

class RobotInfo: public Subsystem {
public:
	PowerDistributionPanel pdp;
	SendableChooser<int*>* position;

	RobotInfo();
};
