#include "ArmSubsystem.h"
#include "../RobotMap.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_tilt_motor(arm_tilt),
		intake_tilt_motor(intake_tilt)
{

}

void ArmSubsystem::SetArmTiltMotorSpeed(float speed) {

}

void ArmSubsystem::SetIntakeTiltMotorSpeed(float speed) {

}

void ArmSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new ArmDefault());
}

void ArmSubsystem::TiltFudge(double target) {

}

void ArmSubsystem::ScoreHighSetpiont() {

}

void ArmSubsystem::ScoreLowSetpoint() {

}

void ArmSubsystem::HangSetpoint() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
