#pragma once

#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"

class IntakeOut : public CommandBase {
public:
	IntakeOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
