#pragma once

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>
#include "Commands/Arm/ArmDefault.h"

class ArmSubsystem : public Subsystem {
private:
	TalonSRX arm_tilt_motor;
	TalonSRX intake_tilt_motor;
public:
	ArmSubsystem();
	void InitDefaultCommand();
	void TiltFudge(double target);
	void ScoreHighSetpiont();
	void ScoreLowSetpoint();
	void HangSetpoint();
	void SetArmTiltMotorSpeed(float speed);
	void SetIntakeTiltMotorSpeed(float speed);
};
