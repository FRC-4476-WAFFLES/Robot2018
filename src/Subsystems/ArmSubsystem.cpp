#include "ArmSubsystem.h"
#include "../RobotMap.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_tilt_motor(arm_tilt),
		intake_tilt_motor(intake_tilt),
		arm_encoder(arm_tilt_encoder_a, arm_tilt_encoder_b),
		wrist_encoder(intake_tilt_encoder_a, arm_tilt_encoder_b),
		left_intake_solenoid(intake_solenoid_extend_1, intake_solenoid_retract_1),
		right_intake_solenoid(intake_solenoid_extend_2, intake_solenoid_retract_2)

{

}

void ArmSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new ArmDefault());


}

void ArmSubsystem::Periodic() {//go to target

	//--------------------wrist pid----------------------//
	arm_tilt_motor.Config_kP(0,0,10);
	arm_tilt_motor.Config_kI(0,0,10);
	arm_tilt_motor.Config_kD(0,0,10);



	//--------------------arm   pid----------------------//
	intake_tilt_motor.Config_kP(0,0,10);
	intake_tilt_motor.Config_kI(0,0,10);
	intake_tilt_motor.Config_kD(0,0,10);
	if(PIDJoystick){
		arm_tilt_motor.Set(TalonSRX::kPositionMode,NextArmPosition);
	}else{

	}

}

void ArmSubsystem::SetUseEncoder(bool useEncoder) {
	if(useEncoder){
		PIDJoystick = true;
	}else{
		PIDJoystick = false;
	}

}

void ArmSubsystem::SetClamp(bool shouldClamp) {//set the intake open/closed
	if(shouldClamp){
		left_intake_solenoid.Set(DoubleSolenoid::kForward);
		right_intake_solenoid.Set(DoubleSolenoid::kForward);
	}else{
		left_intake_solenoid.Set(DoubleSolenoid::kReverse);
		right_intake_solenoid.Set(DoubleSolenoid::kReverse);
	}
}

void ArmSubsystem::SeekTo(float armPosition, float wristPosition) {//set target
	NextArmPosition = armPosition;
	NextWristPosition = wristPosition;

}
