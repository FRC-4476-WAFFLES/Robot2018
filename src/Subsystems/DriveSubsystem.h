#pragma once

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <Spark.h>
#include <Victor.h>
#include "CustomSensors/ADIS16448_IMU.h"
#include <DoubleSolenoid.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/Phoenix.h>
class DriveSubsystem: public frc::Subsystem {
public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void drive(float left, float right);
	void special_turn(float direction);
	ADIS16448_IMU gyro;
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark left1;
	Spark left2;
	Spark left3;
	Victor right1;
	Victor right2;
	Victor right3;
	SpeedControllerGroup left;
	SpeedControllerGroup right;
	DifferentialDrive drive_base;
	DoubleSolenoid specialturnsolenoid;
	TalonSRX specialturnmotor;

};
