#pragma once

#include "CommandBase.h"
#include "Commands/Drive/DriveAutoLines.h"

class WaitForCube : public CommandBase {
public:
	WaitForCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double drive_at_start = 0;
//	DriveAutoLines drive;
//	DriveAutoLines drive_back;
//	int state_thing = 0;
};
