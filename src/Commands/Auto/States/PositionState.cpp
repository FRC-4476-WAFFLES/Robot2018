#include <Commands/Auto/States/PositionState.h>
#include "Subsystems/RobotInfo.h"

PositionState::PositionState(Command* Left, Command* Right) :
		ConditionalCommand("PositionState", Left, Right)
{
	SetTimeout(15.0);
}
bool PositionState::Condition() {
	if(*CommandBase::Info().position->GetSelected() == 1){
		return true;
	}else{
		return false;
	}
}
