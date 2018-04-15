#include "IntakeDefault.h"
#include "Subsystems/IntakeSubsystem.h"
#include "OI.h"
#include "Subsystems/DriveSubsystem.h"
#include "SmartDashboard/SmartDashboard.h"

IntakeDefault::IntakeDefault() :
	CommandBase("IntakeDefault")
{
	Requires(&Intake());
}

// Called just before this Command runs the first time
void IntakeDefault::Initialize() {
	Intake().SetSpeed(0.1);
}
void IntakeDefault::Execute() {
//	if(OI::A){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(OI::B){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(OI::X){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else if(OI::Y){
//		instaid_of_button_held_timer = instaid_of_button_held_timer + 1;
//		SmartDashboard::PutBoolean("default holding", true);
//	}else{
//		SmartDashboard::PutBoolean("default holding", false);
//		instaid_of_button_held_timer = 0;
//	}
//	if(instaid_of_button_held_timer > 50){
//		oi().positioned_outtake = (((20*Drive().GetSpeed())/13180) + 0.3);
//	}else{
//		oi().positioned_outtake = 0.0;
//	}
}
