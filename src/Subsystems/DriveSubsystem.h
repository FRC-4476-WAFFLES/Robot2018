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




	//void special_turn(float direction);

	double target_distance;
	double target_angle;
};
