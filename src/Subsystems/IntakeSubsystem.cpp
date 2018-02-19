#include <SmartDashboard/SmartDashboard.h>
#include <PowerDistributionPanel.h>
#include <RobotState.h>
#include "CommandBase.h"
#include "RobotInfo.h"
#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../OI.h"
#include <DriverStation.h>

IntakeSubsystem::IntakeSubsystem() :
	frc::Subsystem("IntakeSubsystem"),
	intake_motor_1(INTAKE1),
	intake_motor_2(INTAKE2)
{
}

void IntakeSubsystem::ModeChange() {
}

void IntakeSubsystem::Periodic() {
	if(frc::DriverStation::GetInstance().IsOperatorControl()){
		speed = CommandBase::oi().IntakeSpeed();
	}

	intake_motor_1.Set(-speed);
	intake_motor_2.Set(speed);

	if(speed > 0.3) {
		float current = CommandBase::Info().pdp.GetCurrent(10) + CommandBase::Info().pdp.GetCurrent(11);
		hasCube = current > 13.0;
	} else if(speed < -0.3) {
		hasCube = false;
	}

	SmartDashboard::PutBoolean("Has Cube?", hasCube);

}

void IntakeSubsystem::SetSpeed(double newSpeed) {
	this->speed = newSpeed;
}

