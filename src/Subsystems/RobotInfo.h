#pragma once
#include <Commands/Subsystem.h>
#include <PowerDistributionPanel.h>

class RobotInfo: public Subsystem {
public:
	PowerDistributionPanel pdp;

	RobotInfo();
};
