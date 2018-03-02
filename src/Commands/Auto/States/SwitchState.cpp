#include <Commands/Auto/States/SwitchState.h>
#include "DriverStation.h"
SwitchState::SwitchState(Command* Left, Command* Right):
	ConditionalCommand("SwitchState", Left, Right)
{

}

// Called just before this Command runs the first time
bool SwitchState::Condition() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData.length() > 0){
		if(gameData[0] == 'L')
		{
			return true;
		} else {
			return false;
		}
	} else {
		fprintf(stderr, "no position data available -> SwitchState.cpp \n");
		return true;
	}

}
