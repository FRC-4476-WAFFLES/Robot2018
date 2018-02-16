#pragma once
#include "CommandBase.h"
#include "Commands/ConditionalCommand.h"


class SwitchState : public ConditionalCommand {
public:
	SwitchState(Command* Left, Command* Right);
	bool Condition();

};
