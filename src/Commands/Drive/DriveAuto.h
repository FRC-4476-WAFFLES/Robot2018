#pragma once

#include "CommandBase.h"

class DriveAuto : public CommandBase {
public:
	DriveAuto(const char* target);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
