#pragma once
#include <Commands/Subsystem.h>
#include <Victor.h>
#include <DoubleSolenoid.h>

class IntakeSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor intake_motor_1;
	Victor intake_motor_2;
	DoubleSolenoid left_intake_solenoid;
	DoubleSolenoid right_intake_solenoid;

public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void SetIntakeSpeed(double Speed);
	void OpenIntake();
	void CloseIntake();
};

