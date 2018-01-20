#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Commands/Command.h>

#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ArmSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"

CommandBase::CommandBase(const std::string& name) :
		frc::Command(name)
{

}

DriveSubsystem& CommandBase::Drive() {
	static DriveSubsystem subsystem;
	return subsystem;
}

OI& CommandBase::oi() {
	static OI oi;
	return oi;
}

ArmSubsystem& CommandBase::Arm() {
	static ArmSubsystem subsystem;
	return subsystem;
}

IntakeSubsystem& CommandBase::Intake() {
	static IntakeSubsystem subsystem;
	return subsystem;
}
