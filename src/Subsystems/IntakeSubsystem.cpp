#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() :
	frc::Subsystem("IntakeSubsystem"),
	intake_motor_1(intake1),
	intake_motor_2(intake2),
	left_intake_solenoid(intake_solenoid_extend_1, intake_solenoid_retract_1),
	right_intake_solenoid(intake_solenoid_extend_2, intake_solenoid_retract_2)
{

}

void IntakeSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::SetIntakeSpeed(double Speed) {
	intake_motor_1.Set(Speed);
	intake_motor_2.Set(Speed*-1);
}

void IntakeSubsystem::OpenIntake() {
	left_intake_solenoid.Set(DoubleSolenoid::kReverse);
	right_intake_solenoid.Set(DoubleSolenoid::kReverse);
}

void IntakeSubsystem::CloseIntake() {
	left_intake_solenoid.Set(DoubleSolenoid::kForward);
	right_intake_solenoid.Set(DoubleSolenoid::kForward);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
