#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class ScoreScaleLow : public CommandBase {
public:
	ScoreScaleLow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

