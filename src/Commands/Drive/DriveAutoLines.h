#pragma once

#include "CommandBase.h"
#include <vector>

#include <Timer.h>

class DriveAutoLines : public CommandBase {
private:
	double distance;
	double angle;
	double epsilon;
	double last_distance_error;
	double last_angle_error;
	Timer last_time;
	double max_speed;
public:
	DriveAutoLines(double distance, double angle, double epsilon = 25, double speed_max = 0.6);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

