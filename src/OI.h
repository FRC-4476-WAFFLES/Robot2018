#pragma once

#include <Joystick.h>

class OI {
public:
	enum OperatorButton {
		X=1,
		A=2,
		B=3,
		Y=4,
		BumperTopLeft=5,
		BumperTopRight=6,
		Back=7,
		Start=8,
	};
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
