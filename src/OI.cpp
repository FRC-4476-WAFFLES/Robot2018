#include "OI.h"

OI::OI():
	left(0),
	right(1),
	operate(2)
{

}

double OI::ArmFudge() {
	return operate.GetY(Joystick::kLeftHand);
}

double OI::WristFudge() {
	return operate.GetY(Joystick::kRightHand);
}

double OI::IntakeSpeed() {
	return operate.GetRawAxis(5) - operate.GetRawAxis(6);
}
