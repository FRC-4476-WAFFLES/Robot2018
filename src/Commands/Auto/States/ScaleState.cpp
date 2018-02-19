#include <Commands/Auto/States/ScaleState.h>
#include "DriverStation.h"
ScaleState::ScaleState(Command* Left, Command* Right):
	ConditionalCommand("SwitchState", Left, Right)
{

}

// Called just before this Command runs the first time
bool ScaleState::Condition() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData.length() > 0){
		if(gameData[1] == 'L')
		{
			return true;
		} else {
			return false;
		}
	}else{
		fprintf(stderr, "no position data available -> ScaleState.cpp \n");
		return true;
	}

}
