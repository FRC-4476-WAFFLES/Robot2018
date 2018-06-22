#pragma once
#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"

class ToggleDriveMode : public CommandBase {
public:
	ToggleDriveMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


