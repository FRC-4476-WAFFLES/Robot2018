#pragma once

#include "CommandBase.h"

class OperatorTankDrive : public CommandBase {
public:
	OperatorTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
