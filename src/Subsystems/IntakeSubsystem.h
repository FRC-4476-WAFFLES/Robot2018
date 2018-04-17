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
	void SetOuttakeDistance(double driveSpeed);

	void SetSpeed(double speed);
	bool is_outtaking = false;
	bool held = false;
	Timer held_time;
	int instaid_of_button_held_timer = 0;
	double drive_speed = 0;
	double positioned_outtake_speed = 0;
	bool is_button_pressed = false;
	bool drive_outtake_code = false;

};

