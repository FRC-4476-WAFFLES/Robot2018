#include <Commands/Arm/ResetArmEncoder.h>
#include <Subsystems/ArmSubsystem.h>

ResetArmEncoder::ResetArmEncoder():
	CommandBase("ResetArmEncoder")
{
	// TODO Auto-generated constructor stub
}

void ResetArmEncoder::Initialize() {
	Arm().ResetArmEncoder();
}
