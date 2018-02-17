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

class DriveSubsystem: public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP left1;
	VictorSP left2;
	VictorSP left3;
	VictorSP right1;
	VictorSP right2;
	VictorSP right3;
	SpeedControllerGroup left;
	SpeedControllerGroup right;
	DifferentialDrive drive_base;
	//DoubleSolenoid special_turn_solenoid;
	//TalonSRX special_turn_motor;

public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void ModeChange();

	void drive(float left, float right);
	//void special_turn(float direction);
};
