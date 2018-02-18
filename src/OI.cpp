#include "OI.h"
#include "Commands/Arm/ArmDefault.h"
#include "Commands/Arm/HighForwardSetpoint.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Arm/ScoreScaleLow.h"
#include "Commands/Arm/PIDJoystickSwitch.h"
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

	Button* ArmEncSwitch = new JoystickButton(&operate, OperatorButton::Start);
	ArmEncSwitch->WhenReleased(new PIDJoystickSwitch());

	Button* LB = new JoystickButton(&operate, OperatorButton::BumperTopLeft);
	LB->WhenReleased(new ScoreScaleLow);
}

double OI::ArmFudge() {
	return operate.GetRawAxis(1);
}

double OI::WristFudge() {
	return operate.GetRawAxis(5);
}

double OI::IntakeSpeed() {
	return operate.GetRawAxis(3) - 0.5 * operate.GetRawAxis(2);
}
