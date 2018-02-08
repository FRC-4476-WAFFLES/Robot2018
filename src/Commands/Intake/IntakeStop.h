#pragma once

#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"

class IntakeStop : public CommandBase {
public:
	IntakeStop();
	void Initialize();
	bool IsFinished() { return true; };
};

