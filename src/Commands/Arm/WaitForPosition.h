#pragma once

#include "CommandBase.h"

class WaitForPosition : public CommandBase {
public:
	WaitForPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
