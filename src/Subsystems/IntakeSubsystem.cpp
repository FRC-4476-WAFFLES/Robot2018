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
	if(speed < -1){
		is_outtaking = true;
	}else{
		is_outtaking = false;
	}

//	if(OI::A){
//		held_time.Start();
//	}else if(OI::B){
//		held_time.Start();
//	}else if(OI::X){
//		held_time.Start();
//	}else if(OI::Y){
//		held_time.Start();
//	}else{
//		held_time.Stop();
//		held_time.Reset();
//	}
//	if(held_time.Get() > 1000){
//		held = true;
//		SetSpeed(0.5);
//	}else{
//		held = false;
//		SetSpeed(0.0);
//	}


}

void IntakeSubsystem::SetSpeed(double newSpeed) {
	this->speed = newSpeed;
}

