#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() :
	frc::Subsystem("IntakeSubsystem"),
	intake_motor_1(intake1),
	intake_motor_2(intake2)

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
// Put methods for controlling this subsystem
// here. Call these from Commands.
