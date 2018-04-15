#pragma once
#include "CommandBase.h"
#include "Subsystems/IntakeSubsystem.h"
#include "Timer.h"

class IntakeDefault : public CommandBase {
public:
	IntakeDefault();
	void Initialize();
	void Execute();
	bool IsFinished() { return true; };
//	int instaid_of_button_held_timer = 0;
};
