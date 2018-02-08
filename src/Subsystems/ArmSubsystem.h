#pragma once

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/IMotorController.h>
#include <ctre/Phoenix.h>
#include "Commands/Arm/ArmDefault.h"
#include "DoubleSolenoid.h"
#include "Encoder.h"

class ArmSubsystem : public Subsystem {
private:
	TalonSRX arm_tilt_motor;
	TalonSRX intake_tilt_motor;
	Encoder arm_encoder;
	Encoder wrist_encoder;
public:
	ArmSubsystem();
	void InitDefaultCommand();

	void Periodic();
	void SetUseEncoder(bool useEncoder);
	void SetClamp(bool shouldClamp);
	void SeekTo(float armPosition, float wristPosition);
	float NextArmPosition;
	float NextWristPosition;
	bool PIDJoystick = true;


	const float INTAKE_ARM = 0;
	const float INTAKE_WRIST = 0;
	const float LOW_FORWARD_ARM = 0;
	const float LOW_FORWARD_WRIST = 0;
	const float HIGH_FORWARD_ARM = 0;
	const float HIGH_FORWARD_WRIST = 0;
	const float HIGH_REVERSE_ARM = 0;
	const float HIGH_REVERSE_WRIST = 0;

	DoubleSolenoid left_intake_solenoid;
	DoubleSolenoid right_intake_solenoid;
};
