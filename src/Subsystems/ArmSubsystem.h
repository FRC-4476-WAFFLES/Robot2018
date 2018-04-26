#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <AnalogInput.h>
#include "DoubleSolenoid.h"
#include "Timer.h"
#include <PowerDistributionPanel.h>
#include <Talon.h>
#include "DigitalOutput.h"


class ArmSubsystem : public Subsystem {
private:
	WPI_TalonSRX arm_motor;
	WPI_VictorSPX arm_motor_slave;
	WPI_TalonSRX wrist_motor;
	Timer t;
	DoubleSolenoid intake_solenoid;
	AnalogInput infrared_sensor;
	Talon test_motor;

	bool PIDJoystick;
	float PosWhenSeekToSet_Arm = 0;
	float PosWhenSeekToSet_Wrist = 0;
	double current_distance_voltage = 0;


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
	void ResetArmEncoder();

// Middle is -1335
	constexpr static float INTAKE_ARM = 25; //28
	constexpr static float INTAKE_WRIST = -750;//-726, 678
	constexpr static float LOW_FORWARD_ARM = 113;
	constexpr static float LOW_FORWARD_WRIST = -368;
	constexpr static float HIGH_FORWARD_ARM = 672;
	constexpr static float HIGH_FORWARD_WRIST = -1600;
	constexpr static float HIGH_FORWARD_LOW_WRIST = -2490;
	constexpr static float HIGH_REVERSE_ARM = 672;
	constexpr static float HIGH_REVERSE_WRIST = -535;
	constexpr static float HIGH_REVERSE_LOW_WRIST = -180;
	constexpr static float TRAVEL_WRIST = -368;
	constexpr static float FULL_IN_WRIST = -20;
	constexpr static float LOW_LEGAL_LIMIT = 200;
	constexpr static float HIGH_LEGAL_LIMIT = 520;
	constexpr static float WRIST_EXCHANGE_ZONE = -715;


	bool PIDModeEnabled;
	int WristArmSwitch = 4;
	bool outtaking = false;
	bool toggled = false;
	bool intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone = false;

	float NextArmPosition = 0;
	float NextWristPosition = 0;
	float NextWristPosition4 = 0;
	float AlternateWristPosition = 0;
	bool hasCUBE = 0;
	DigitalOutput lights;

};
