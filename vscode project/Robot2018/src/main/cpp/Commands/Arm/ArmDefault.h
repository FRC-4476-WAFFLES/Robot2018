#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class ArmDefault : public CommandBase {
public:
	ArmDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


