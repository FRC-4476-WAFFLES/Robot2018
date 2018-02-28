#pragma once

#include "CommandBase.h"
#include <vector>
#include <pathfinder.h>

class DriveAuto : public CommandBase {
private:
	std::vector<Waypoint> waypoints;
	std::vector<Segment> left_trajectory;
	std::vector<Segment> right_trajectory;
	EncoderFollower left_follower;
	EncoderFollower right_follower;
public:
	DriveAuto(std::vector<Waypoint> target);
	DriveAuto(std::string str) :
		CommandBase(str)
	{
		printf("Not working auto: %s\n", str.c_str());
	}

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

