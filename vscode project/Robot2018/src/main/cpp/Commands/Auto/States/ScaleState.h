#pragma once
#include "CommandBase.h"
#include "Commands/ConditionalCommand.h"


class ScaleState : public ConditionalCommand {
public:
	ScaleState(Command* Left, Command* Right);
	bool Condition();

};
