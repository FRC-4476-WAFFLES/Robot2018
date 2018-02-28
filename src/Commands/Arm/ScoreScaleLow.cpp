#include <Commands/Arm/ScoreScaleLow.h>

ScoreScaleLow::ScoreScaleLow():
	CommandBase("HighSetpoint")
{
	Requires(&Arm());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ScoreScaleLow::Initialize() {
	Arm().SetClamp(true);
	Arm().SeekTo(Arm().SCORE_SCALE_LOW_ARM, Arm().SCORE_SCALE_LOW_WRIST);
}

// Called repeatedly when this Command is scheduled to run
void ScoreScaleLow::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ScoreScaleLow::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ScoreScaleLow::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScoreScaleLow::Interrupted() {

}
