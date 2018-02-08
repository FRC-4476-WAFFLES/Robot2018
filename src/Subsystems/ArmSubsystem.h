#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "DoubleSolenoid.h"

class ArmSubsystem : public Subsystem {
private:
	WPI_TalonSRX arm_motor;
	WPI_TalonSRX wrist_motor;

	DoubleSolenoid left_intake_solenoid;
	DoubleSolenoid right_intake_solenoid;

	float NextArmPosition;
	float NextWristPosition;
	bool PIDJoystick;

public:
	ArmSubsystem();
	void Periodic();
	void ModeChange();

	void SetUseEncoder(bool useEncoder);
	void SetClamp(bool shouldClamp);
	void SeekTo(float armPosition, float wristPosition);

	const float INTAKE_ARM = 0;
	const float INTAKE_WRIST = 0;
	const float LOW_FORWARD_ARM = 0;
	const float LOW_FORWARD_WRIST = 0;
	const float HIGH_FORWARD_ARM = 0;
	const float HIGH_FORWARD_WRIST = 0;
	const float HIGH_REVERSE_ARM = 0;
	const float HIGH_REVERSE_WRIST = 0;
};
