#pragma once

#include "CommandBase.h"
#include <vector>

#include <Timer.h>

class DriveAutoTime : public CommandBase {
private:
	double drive_speed;
	double drivetime;
	Timer time_since_start;
	double keep_going = true;
public:
	DriveAutoTime(double time, double percent_speed);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

