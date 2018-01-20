#pragma once
#include <Commands/Subsystem.h>
#include <Victor.h>

class IntakeSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor intake_motor_1;
	Victor intake_motor_2;

public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void SetIntakeSpeed(double Speed);
};

