#pragma once
#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class ToggleAlternate : public CommandBase {
public:
	ToggleAlternate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


