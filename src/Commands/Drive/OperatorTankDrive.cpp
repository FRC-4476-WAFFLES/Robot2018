#include "OperatorTankDrive.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ArmSubsystem.h"
OperatorTankDrive::OperatorTankDrive():
	CommandBase("OperatorTankDrive")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Drive());
}

// Called just before this Command runs the first time
void OperatorTankDrive::Initialize() {
	sec.Stop();
	sec.Reset();
}

// Called repeatedly when this Command is scheduled to run
void OperatorTankDrive::Execute() {
	if(Arm().WristArmSwitch != 4){
		Drive().right1.ConfigContinuousCurrentLimit(35, 10);
		Drive().right1.ConfigPeakCurrentLimit(35, 10);
		Drive().right1.ConfigPeakCurrentDuration(10, 10);
		Drive().left1.ConfigContinuousCurrentLimit(35, 10);
		Drive().left1.ConfigPeakCurrentLimit(35, 10);
		Drive().left1.ConfigPeakCurrentDuration(10, 10);
	}else{
		Drive().right1.ConfigContinuousCurrentLimit(40, 10);
		Drive().right1.ConfigPeakCurrentLimit(40, 10);
		Drive().right1.ConfigPeakCurrentDuration(10, 10);
		Drive().left1.ConfigContinuousCurrentLimit(40, 10);
		Drive().left1.ConfigPeakCurrentLimit(40, 10);
		Drive().left1.ConfigPeakCurrentDuration(40, 10);
	}
	Drive().drive(oi().left.GetY(), oi().right.GetY());

	time_coeff = 1/sec.Get();
	feet_in_last_second = (((Drive().Left() + Drive().Right() / 2.0) - last_encoder_position) /639)*time_coeff;
	sec.Reset();
	sec.Start();
	last_encoder_position = Drive().Left() + Drive().Right() / 2.0;
	Drive().speed = feet_in_last_second;
}

// Make this return true when this Command no longer needs to run execute()
bool OperatorTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OperatorTankDrive::End() {
	Drive().drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperatorTankDrive::Interrupted() {
	End();
}
