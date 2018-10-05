#include "OI.h"
#include "Commands/Arm/ArmDefault.h"
#include "Commands/Arm/HighForwardSetpoint.h"
#include "Commands/Arm/HighReverseSetpoint.h"
#include "Commands/Arm/IntakeDown.h"
#include "Commands/Arm/LowSetpoint.h"
#include "Commands/Arm/ToggleAlternate.h"
#include "Commands/Arm/PIDJoystickSwitch.h"
#include "Commands/Arm/ToggleGrab.h"
#include "Commands/Arm/ResetArmEncoder.h"
#include "Commands/Drive/ToggleDriveMode.h"
#include <math.h>
#include "Buttons/Button.h"
#include "Buttons/JoystickButton.h"
#include <smartdashboard/SmartDashboard.h>

OI::OI():
	left(1),
	right(0),
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
	LB->WhenReleased(new ToggleAlternate());

	Button* RB = new JoystickButton(&operate, OperatorButton::BumperTopRight);
	RB->WhenReleased(new ToggleGrab());

	Button* ToggleDrive = new JoystickButton(&right, right.GetRawButton(11));
	ToggleDrive->WhenReleased(new ToggleDriveMode());

	SmartDashboard::PutData(new ResetArmEncoder());

}

double OI::ArmFudge() {
	return -operate.GetRawAxis(1);
}

double OI::WristFudge() {
	return -operate.GetRawAxis(5);
}

double OI::IntakeSpeed() {

	double in = operate.GetRawAxis(3);
	double out =  operate.GetRawAxis(2);
	return in * in - 1.0 * out * out + positioned_outtake;//0.4->1.0
}
