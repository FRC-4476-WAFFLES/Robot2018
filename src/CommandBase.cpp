#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Commands/Command.h>

#include "Subsystems/DriveSubsystem.h"

CommandBase::CommandBase(const std::string& name) :
		frc::Command(name)
{

}

DriveSubsystem& CommandBase::drive() {
	static DriveSubsystem subsystem;
	return subsystem;
}

OI& CommandBase::oi() {
	static OI oi;
	return oi;
}
