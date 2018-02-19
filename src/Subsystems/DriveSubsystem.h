#pragma once

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <VictorSP.h>
#include <DoubleSolenoid.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>
#include <pathfinder.h>
#include <ADXRS450_Gyro.h>

class DriveSubsystem: public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX left1;
	WPI_VictorSPX left2;
	WPI_VictorSPX left3;
	WPI_TalonSRX right1;
	WPI_VictorSPX right2;
	WPI_VictorSPX right3;
	ADXRS450_Gyro gyro;
	//DoubleSolenoid special_turn_solenoid;
	//TalonSRX special_turn_motor;

public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void ModeChange();

	void drive(float left, float right);
	void Prints();

	float Right();
	float Left();
	float Gyro();

	constexpr static float MAX_SPEED = 1.0; // feet/s
	constexpr static float MAX_ACCEL = 1.0; // feet/s/s
	constexpr static float MAX_JERK = 10.0; // feet/s/s/s
	constexpr static float ANGLE_P = 0.8;

	EncoderConfig left_config = {.initial_position = 0, .ticks_per_revolution = 128, .wheel_circumference = (6.0/12.0)*M_PI, .kp = 0.5, .ki = 0.0, .kd = 0.0, .kv = 1.0/30.0, .ka = 0.0};
	EncoderConfig right_config = {.initial_position = 0, .ticks_per_revolution = 128, .wheel_circumference = (6.0/12.0)*M_PI, .kp = 0.5, .ki = 0.0, .kd = 0.0, .kv = 1.0/30.0, .ka = 0.0};
	//void special_turn(float direction);

	double target_distance;
	double target_angle;
};
