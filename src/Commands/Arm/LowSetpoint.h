#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class LowSetpoint : public CommandBase {
public:
	LowSetpoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
