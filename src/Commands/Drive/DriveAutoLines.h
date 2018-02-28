#pragma once

#include "CommandBase.h"
#include <vector>
#include <pathfinder.h>
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
	DriveAutoLines(double distance, double angle, double epsilon = 15, double speed_max = 0.5);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
