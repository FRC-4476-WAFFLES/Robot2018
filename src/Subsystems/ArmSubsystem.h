#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "DoubleSolenoid.h"
#include "Timer.h"

class ArmSubsystem : public Subsystem {
private:
	WPI_TalonSRX arm_motor;
	WPI_VictorSPX arm_motor_slave;
	WPI_TalonSRX wrist_motor;
	Timer t;

	DoubleSolenoid intake_solenoid;

	bool PIDJoystick;


	float PosWhenSeekToSet_Arm = 0;
	float PosWhenSeekToSet_Wrist = 0;

public:
	ArmSubsystem();
	void Periodic();
	void ModeChange();
	void Prints();

	void SetUseEncoder(bool useEncoder);
	void SetClamp(bool shouldClamp);
	bool GetClamp();
	void SeekTo(float armPosition, float wristPosition);
	void SeekTo(float armPosition, float wristPosition, float alternateWristPosition);
	void ToggleAlternate();

// Middle is -1335
	constexpr static float INTAKE_ARM = 28;
	constexpr static float INTAKE_WRIST = -726;
	constexpr static float LOW_FORWARD_ARM = 110;
	constexpr static float LOW_FORWARD_WRIST = -368;
	constexpr static float HIGH_FORWARD_ARM = 713;
	constexpr static float HIGH_FORWARD_WRIST = -1600;
	constexpr static float HIGH_FORWARD_LOW_WRIST = -2490;
	constexpr static float HIGH_REVERSE_ARM = 713;
	constexpr static float HIGH_REVERSE_WRIST = -535;
	constexpr static float HIGH_REVERSE_LOW_WRIST = -180;
	constexpr static float TRAVEL_WRIST = -368;
	constexpr static float FULL_IN_WRIST = -20;
	constexpr static float LOW_LEGAL_LIMIT = 200;
	constexpr static float HIGH_LEGAL_LIMIT = 520;

	bool PIDModeEnabled;
	int WristArmSwitch = 4;

	float NextArmPosition = 0;
	float NextWristPosition = 0;
	float AlternateWristPosition = 0;
};
