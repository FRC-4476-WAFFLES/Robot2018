#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class HighForwardSetpoint : public CommandBase {
public:
	HighForwardSetpoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

