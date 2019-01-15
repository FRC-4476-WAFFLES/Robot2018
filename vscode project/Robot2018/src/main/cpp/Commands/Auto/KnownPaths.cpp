#include "KnownPaths.h"

#include <vector>
#include <pathfinder.h>

std::vector<Waypoint> DrivePastLine(){
	std::vector<Waypoint> PointArray1;
	PointArray1.push_back({.x = 0, .y = 0, .angle = 0});
	PointArray1.push_back({.x = 5, .y = 0, .angle = 0});
	return PointArray1;
}

std::vector<Waypoint> DriveToLeftSwitchFromCenter(){
	std::vector<Waypoint> PointArray2;
	PointArray2.push_back({.x = 0, .y = 0, .angle = 0});
//	PointArray2.push_back({.x = 9.833, .y = 3.5, .angle = 0});
	PointArray2.push_back({.x = 9.833, .y = 9.833, .angle = d2r(45)});

	return PointArray2;
}



