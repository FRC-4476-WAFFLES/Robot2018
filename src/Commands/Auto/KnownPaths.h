#pragma once
#include <vector>
#include <pathfinder.h>

std::vector<Waypoint> DrivePastLine(){
	std::vector<Waypoint> PointArray1;
	PointArray1.push_back({0, 0, 0});
	PointArray1.push_back({5, 0, 0});
	return PointArray1;
}
/*
std::vector<Waypoint> Mirror(std::vector<Waypoints> Original){

}
*/
