#pragma once

#include "CommandBase.h"
#include "Subsystems/ArmSubsystem.h"

class PIDJoystickSwitch : public CommandBase {
public:
	PIDJoystickSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

