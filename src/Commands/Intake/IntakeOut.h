#pragma once

#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"

class IntakeOut : public CommandBase {
public:
	IntakeOut(): IntakeOut(0.5) {}
	IntakeOut(double spd);
	void Initialize();
	bool IsFinished() { return true; };
	double speed;
};
