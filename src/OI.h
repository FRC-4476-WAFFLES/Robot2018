#pragma once

#include <Joystick.h>

class OI {
public:
	Joystick left;
	Joystick right;
	Joystick operate;

	OI();

	// Arm and wrist fudge
	double ArmFudge();
	double WristFudge();

	// Intake speed
	double IntakeSpeed();
};
