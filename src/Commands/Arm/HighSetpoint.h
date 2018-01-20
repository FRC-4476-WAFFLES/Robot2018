#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class HighSetpoint : public CommandBase {
public:
	HighSetpoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

