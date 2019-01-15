#include "NonLoopingVexEncoder.h"
#include <cmath>

NonLoopingVexEncoder::NonLoopingVexEncoder(int port, float tearpoint):
  tearpoint(tearpoint)
{
	counter = new Counter(port);
	// TODO: Make this actually read the PWM, not the half period as that can vary
	// Look at this old (at the time of writing) thread for some ideas:
	// http://forums.usfirst.org/showthread.php?12086-Measuring-PWM-input-signals/page2
	counter->SetSemiPeriodMode(true);
	counter->SetSamplesToAverage(1);
}

float NonLoopingVexEncoder::GetAngle() {
	// Nothing fancy anymore
	auto raw = GetRawAngle();
	auto result = fmod(fmod(raw - tearpoint, 360.0) + 360.0, 360.0) + tearpoint;
	return result;
}

double NonLoopingVexEncoder::PIDGet() {
	return GetAngle();
}

float NonLoopingVexEncoder::GetRawAngle() {
	// PWM is 220Hz (from the docs) (And convert to degrees).
	// See top for an idea on how to fix this hardcoded 240.0
	float angle = (counter->GetPeriod()*240.0)*360.0;
	return angle;
}

void NonLoopingVexEncoder::Reset() {
}
