#pragma once

#include "CommandBase.h"

class WaitForCube : public CommandBase {
public:
	WaitForCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
