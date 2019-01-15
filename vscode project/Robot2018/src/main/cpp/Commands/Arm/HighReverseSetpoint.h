#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class HighReverseSetpoint : public CommandBase {
public:
	HighReverseSetpoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

