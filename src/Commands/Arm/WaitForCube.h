#pragma once

#include "CommandBase.h"
#include "Commands/Drive/DriveAutoLines.h"
#include "Timer.h"

class WaitForCube : public CommandBase {
public:
	WaitForCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer wait_for_intake;

};
