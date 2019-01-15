#pragma once
#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class IntakeDown : public CommandBase {
public:
	IntakeDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


