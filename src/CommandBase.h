#pragma once

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"

class DriveSubsystem;
class ArmSubsystem;
class IntakeSubsystem;
class RobotInfo;

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	explicit CommandBase(const std::string& name);

	static void ModeChange();
	static void Prints();

	// Create a single static instance of all of your subsystems
	static ArmSubsystem& Arm();
	static DriveSubsystem& Drive();
	static IntakeSubsystem& Intake();
	static RobotInfo& Info();
	static OI& oi();
};
