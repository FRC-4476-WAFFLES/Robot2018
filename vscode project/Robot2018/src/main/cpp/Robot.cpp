#include <Commands/Auto/AutoRightToScale.h>
#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Compressor.h>
//#include <Commands/Auto/AutoScoreSwitchFromCenter.h>
#include <Subsystems/ArmSubsystem.h>

#include "Commands/Auto/AutoDoNothing.h"
#include "Commands/Auto/AutoDriveForward.h"
#include "CommandBase.h"
#include "Commands/Auto/AutoMiddleToSwitch.h"
#include "Commands/Auto/AutoSideToSwitchOrScale.h"
#include "Commands/Auto/AutoRightToScale.h"
#include "Commands/PrintCommand.h"
#include "Commands/Auto/States/SwitchState.h"
#include "Commands/Auto/States/ScaleState.h"
#include "Commands/Auto/States/PositionState.h"
#include "Commands/Intake/IntakeOut.h"

class Robot: public frc::IterativeRobot {
public:
	Robot():
		IterativeRobot(),
		test_auto(0.5),
		switch_print(new PrintCommand("Switch is left\n"), new PrintCommand("Switch is right\n")),
		scale_print(new PrintCommand("Scale is left\n"), new PrintCommand("Scale is right\n")),
		position_print(new PrintCommand("Position is left\n"), new PrintCommand("Position is right\n"))
	{
	}

	void RobotInit() override {
		compressor = std::make_unique<Compressor>();
		compressor.get()->SetClosedLoopControl(true);
		chooser.AddDefault("Nothing", &do_nothing);
		chooser.AddObject("DriveForward", &drive_forward);
		chooser.AddObject("SwitchMiddle", &middle_to_switch);
		chooser.AddObject("SwitchOrScale", &switch_or_scale);
		chooser.AddObject("RightScale", &right_scale);
		chooser.AddObject("TestAuto", &test_auto);

		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		CommandBase::Info();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {
		CommandBase::ModeChange();
	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		CommandBase::Prints();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		CommandBase::Arm().NextArmPosition = 0;
		CommandBase::Arm().NextWristPosition = 0;
		CommandBase::Arm().WristArmSwitch = 5;

		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}

		CommandBase::ModeChange();

		autonomousCommand = chooser.GetSelected();

		switch_print.Start();
		scale_print.Start();
		position_print.Start();
		if (autonomousCommand != nullptr) {
			fprintf(stderr, "Starting auto %s\n", autonomousCommand->GetName().c_str());
			autonomousCommand->Start();
		} else {
			fprintf(stderr, "No auto\n");
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		CommandBase::Prints();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}

		CommandBase::ModeChange();
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		CommandBase::Prints();
	}

	void TestInit() override {
	}

	void TestPeriodic() override {
	}

private:
	frc::Command* autonomousCommand;
	AutoDoNothing do_nothing;
	AutoDriveForward drive_forward;
	AutoMiddleToSwitch middle_to_switch;
	AutoSideToSwitchOrScale switch_or_scale;
	AutoRightToScale right_scale;

	IntakeOut test_auto;

	SwitchState switch_print;
	ScaleState scale_print;
	PositionState position_print;

	frc::SendableChooser<frc::Command*> chooser;
	std::unique_ptr<Compressor> compressor;
};

START_ROBOT_CLASS(Robot)
