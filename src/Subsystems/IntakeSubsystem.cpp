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
#include "Subsystems/ArmSubsystem.h"

IntakeSubsystem::IntakeSubsystem() :
	frc::Subsystem("IntakeSubsystem"),
	intake_motor_1(INTAKE1),
	intake_motor_2(INTAKE2)
{
}//things

void IntakeSubsystem::ModeChange() {
}

void IntakeSubsystem::Periodic() {
	if(frc::DriverStation::GetInstance().IsOperatorControl()){
		speed = CommandBase::oi().IntakeSpeed();
	}

	intake_motor_1.Set(-speed);
	intake_motor_2.Set(speed);

	if(CommandBase::oi().operate.GetRawButton(CommandBase::oi().OperatorButton::Back)){
		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
		SmartDashboard::PutBoolean("default holding", true);
		drive_outtake_code = true;
//	}else if(CommandBase::oi().operate.GetRawButton(CommandBase::oi().OperatorButton::B)){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//
//	}else if(CommandBase::oi().operate.GetRawButton(CommandBase::oi().OperatorButton::X)){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(CommandBase::oi().operate.GetRawButton(CommandBase::oi().OperatorButton::Y)){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
	}else{
		SmartDashboard::PutBoolean("default holding", false);
		instaid_of_button_held_timer = 0;
		drive_outtake_code = false;
	}
	if(instaid_of_button_held_timer > 1){
//		positioned_outtake_speed = (((20*drive_speed)/13180) + 0.3);
		positioned_outtake_speed = drive_speed;
	}else{
		positioned_outtake_speed = 0.0;
	}

	SmartDashboard::PutNumber("holding counter", instaid_of_button_held_timer);
	SmartDashboard::PutBoolean("is button pressed", CommandBase::oi().operate.GetRawButtonPressed(CommandBase::oi().OperatorButton::A));

	if(speed > 0.1 && CommandBase::Arm().intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone && CommandBase::Arm().hasCUBE && frc::DriverStation::GetInstance().IsOperatorControl()){
		intake_clamp_timer.Start();
	}else{
		intake_clamp_timer.Stop();
		intake_clamp_timer.Reset();
	}

	if(speed < -0.1 && CommandBase::Arm().intake_down_position_so_that_the_alt_position_can_use_clamp_for_the_exchange_zone && frc::DriverStation::GetInstance().IsOperatorControl()){
		CommandBase::Arm().SetClamp(false);
	}

	if(intake_clamp_timer.Get() > 0.2){
		CommandBase::Arm().SetClamp(true);
	}
}

void IntakeSubsystem::SetSpeed(double newSpeed) {
	this->speed = newSpeed;
}

void IntakeSubsystem::SetOuttakeDistance(double driveSpeed){
	SetSpeed(((20*driveSpeed)/13180) + 0.3);
}
