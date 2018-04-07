#include "IntakeDefault.h"
#include "Subsystems/IntakeSubsystem.h"
#include "OI.h"
#include "Subsystems/DriveSubsystem.h"

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
	if(OI::A){
		ButtonHeld.Start();
	}else if(OI::B){
		ButtonHeld.Start();
	}else if(OI::X){
		ButtonHeld.Start();
	}else if(OI::Y){
		ButtonHeld.Start();
	}else{
		ButtonHeld.Stop();
		ButtonHeld.Reset();
	}
	if(ButtonHeld.Get() > 1){
		Intake().SetOuttakeDistance(Drive().GetSpeed());
	}else{
		Intake().SetSpeed(0.0);
	}
}
