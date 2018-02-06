#include "ArmSubsystem.h"
#include "../RobotMap.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_tilt_motor(arm_tilt),
		intake_tilt_motor(intake_tilt),
		left_intake_solenoid(intake_solenoid_extend_1, intake_solenoid_retract_1),
		right_intake_solenoid(intake_solenoid_extend_2, intake_solenoid_retract_2)
{

}

void ArmSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new ArmDefault());

}

void ArmSubsystem::Periodic() {

}

void ArmSubsystem::SetUseEncoder(bool useEncoder) {

}

void ArmSubsystem::SetClamp(bool shouldClamp) {


}

void ArmSubsystem::SeekTo(float armPosition, float wristPosition) {
	NextArmPosition = armPosition;
	NextWristPosition = wristPosition;

}
