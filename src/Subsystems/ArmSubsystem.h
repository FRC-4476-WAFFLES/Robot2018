#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "DoubleSolenoid.h"

class ArmSubsystem : public Subsystem {
private:
	WPI_TalonSRX arm_motor;
	WPI_VictorSPX arm_motor_slave;
	WPI_TalonSRX wrist_motor;

	DoubleSolenoid intake_solenoid;

	float NextArmPosition;
	float NextWristPosition;
	bool PIDJoystick = false;


	float PosWhenSeekToSet_Arm = 0;
	float PosWhenSeekToSet_Wrist = 0;

public:
	ArmSubsystem();
	void Periodic();
	void ModeChange();
	void Prints();

	void SetUseEncoder(bool useEncoder);
	void SetClamp(bool shouldClamp);
	void SeekTo(float armPosition, float wristPosition);

	const float INTAKE_ARM = 0;
	const float INTAKE_WRIST = 100;//for testing
	const float LOW_FORWARD_ARM = 0;
	const float LOW_FORWARD_WRIST = 963;//for testing
	const float HIGH_FORWARD_ARM = 0;
	const float HIGH_FORWARD_WRIST = 356;//for testing
	const float HIGH_REVERSE_ARM = 0;
	const float HIGH_REVERSE_WRIST = 100;//for testing
	const float FULL_IN_WRIST = 100;//for testing
	bool PIDModeEnabled;
	int WristArmSwitch = 1;
};
