#pragma once
#include <Timer.h>
#include "CommandBase.h"

class OperatorTankDrive : public CommandBase {
public:
	OperatorTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer sec;
	double feet_in_last_second = 0.0;
	float last_encoder_position = 0.0;
	float time_coeff = 0.0;
};
