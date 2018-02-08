#pragma once
#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"

class IntakeDefault : public CommandBase {
public:
	IntakeDefault();
	void Initialize();
	bool IsFinished() { return true; };
};
