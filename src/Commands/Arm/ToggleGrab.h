#pragma once
#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class ToggleGrab : public CommandBase {
public:
	ToggleGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


