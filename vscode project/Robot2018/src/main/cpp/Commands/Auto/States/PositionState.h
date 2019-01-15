#pragma once

#include "CommandBase.h"
#include "Commands/ConditionalCommand.h"

class PositionState : public ConditionalCommand {
public:
	PositionState(Command* Left, Command* Right);
	bool Condition();
};

