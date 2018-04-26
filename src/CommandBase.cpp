#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Commands/Command.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ArmSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/RobotInfo.h"

CommandBase::CommandBase(const std::string& name) :
		frc::Command(name)
{

}

void CommandBase::Prints() {
	SmartDashboard::PutData(Scheduler::GetInstance());
	Arm().Prints();
	Drive().Prints();
}

void CommandBase::ModeChange() {
	Arm().ModeChange();
	Drive().ModeChange();
	Intake().ModeChange();
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

RobotInfo& CommandBase::Info() {
	static RobotInfo subsystem;
	return subsystem;
}
