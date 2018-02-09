#include "OI.h"
#include "Commands/Arm/ArmDefault.h"
#include "Commands/Arm/HighForwardSetpoint.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/LowSetpoint.h"
#include <math.h>
#include "Buttons/Button.h"
#include "Buttons/JoystickButton.h"


OI::OI():
	left(0),
	right(1),
	operate(2)
{
	Button* ScoreHighBack = new JoystickButton(&operate, OperatorButton::Y);
	ScoreHighBack->WhenReleased(new HighReverseSetpoint());

	Button* ScoreHighFront = new JoystickButton(&operate,OperatorButton::X);
	ScoreHighFront->WhenReleased(new HighForwardSetpoint());

	Button* ScoreLow = new JoystickButton(&operate, OperatorButton::A);
	ScoreLow->WhenReleased(new LowSetpoint());

	Button* Lowest = new JoystickButton(&operate, OperatorButton::B);
	Lowest->WhenReleased(new IntakeDown());
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
