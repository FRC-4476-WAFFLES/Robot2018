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
#include "DriveSubsystem.h"

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

//
//
//	if(OI::OI().operate.GetRawButtonPressed(OI::OperatorButton::A)){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(!OI::B){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//
//	}else if(!OI::X){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(!OI::Y){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else{
//		SmartDashboard::PutBoolean("default holding", false);
//		instaid_of_button_held_timer = 0;
//	}
//	if(instaid_of_button_held_timer > 50){
////		positioned_outtake_speed = (((20*drive_speed)/13180) + 0.3);
//		positioned_outtake_speed = drive_speed;
//	}else{
//		positioned_outtake_speed = 0.0;
//	}
//	SmartDashboard::PutNumber("holding counter", instaid_of_button_held_timer);
//	SmartDashboard::PutBoolean("is button pressed", OI::OI().operate.GetRawButtonPressed(OI::OperatorButton::A));

}

void IntakeSubsystem::SetSpeed(double newSpeed) {
	this->speed = newSpeed;
}

void IntakeSubsystem::SetOuttakeDistance(double driveSpeed){
	SetSpeed(((20*driveSpeed)/13180) + 0.3);
}
