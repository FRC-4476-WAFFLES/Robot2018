#pragma once
#include <Commands/Subsystem.h>
#include <VictorSP.h>
#include <Timer.h>

class IntakeSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP intake_motor_1;
	VictorSP intake_motor_2;

	double speed = 0.0;
	double hasCube = false;

public:
	IntakeSubsystem();
	void Periodic();
	void ModeChange();

	void SetSpeed(double speed);
	bool is_outtaking = false;
	bool held = false;
	Timer held_time;
};

