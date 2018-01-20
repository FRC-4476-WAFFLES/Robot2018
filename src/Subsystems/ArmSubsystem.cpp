#include "ArmSubsystem.h"
#include "../RobotMap.h"

ArmSubsystem::ArmSubsystem() :
		frc::Subsystem("ArmSubsystem"),
		arm_tilt_motor(arm_tilt),
		intake_tilt_motor(intake_tilt)
{

}

void ArmSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	 SetDefaultCommand(new ArmDefault());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
