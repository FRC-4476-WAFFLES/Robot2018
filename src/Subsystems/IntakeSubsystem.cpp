#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../OI.h"

IntakeSubsystem::IntakeSubsystem() :
	frc::Subsystem("IntakeSubsystem"),
	intake_motor_1(INTAKE1),
	intake_motor_2(INTAKE2)
{
}

void IntakeSubsystem::ModeChange() {
}

void IntakeSubsystem::Periodic() {
	intake_motor_1.Set(CommandBase::oi().IntakeSpeed());
	intake_motor_2.Set(-CommandBase::oi().IntakeSpeed());
}

void IntakeSubsystem::SetSpeed(double newSpeed) {
	this->speed = newSpeed;
}

