#pragma once

#include "WPILib.h"

class NonLoopingVexEncoder: public SensorBase, public PIDSource {
private:
	Counter* counter;
	const float tearpoint;
public:
	// Initialize a new sensor. tearpoint will be the place where the sensor is discontinuous
	NonLoopingVexEncoder(int port, float tearpoint = 0.0);

	// Get the angle (in degrees) that the sensor is reading. Does not account for continuous rotation.
	float GetRawAngle();

	// Gets the angle of the sensor. Will be in the range (break_angle%360) < x < (break_angle%360)+360
	float GetAngle();
	double PIDGet() override;

	// Does nothing
	void Reset();
};
