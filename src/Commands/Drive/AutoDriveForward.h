#pragma once

#include "CommandBase.h"

class AutoDriveForward : public CommandBase {
public:
	AutoDriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
