#pragma once

#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"

class IntakeIn : public CommandBase {
public:
	IntakeIn();
	void Initialize();
	bool IsFinished() { return true; };
};
