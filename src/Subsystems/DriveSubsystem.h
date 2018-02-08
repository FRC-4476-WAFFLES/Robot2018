#pragma once

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <Spark.h>
#include <Victor.h>
#include "CustomSensors/ADIS16448_IMU.h"
#include <DoubleSolenoid.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include <ctre/Phoenix.h>

class DriveSubsystem: public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_VictorSPX left1;
	WPI_VictorSPX left2;
	WPI_VictorSPX left3;
	WPI_VictorSPX right1;
	WPI_VictorSPX right2;
	WPI_VictorSPX right3;
	SpeedControllerGroup left;
	SpeedControllerGroup right;
	DifferentialDrive drive_base;
	DoubleSolenoid special_turn_solenoid;
	TalonSRX special_turn_motor;

public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void ModeChange();

	void drive(float left, float right);
	void special_turn(float direction);
	ADIS16448_IMU gyro;
};
