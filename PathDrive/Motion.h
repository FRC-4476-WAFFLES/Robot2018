#pragma once
#include <cmath>
#include <algorithm>
#include "Point2.h"

float clamp(float v, float min, float max) {
	if(v < min) {
		return min;
	} else if(v > max) {
		return max;
	} else {
		return v;
	}
}

float lerp(float mix, float a, float b) {
	return mix*a + (1.0-mix)*b;
}

float rsmall(float r) {
	return fmod(fmod(r, 2*M_PI) + 3*M_PI, 2*M_PI) - M_PI;
}

// Interpolates between angles
float rlerp(float mix, float ia, float ib) {
	float a = rsmall(ia);
	float b = rsmall(ib);

	float diff = fabs(a - b);
	return lerp(mix, a, b);
}


class Motion {
public:
	float turnRate;
	float forwardRate;

	Motion():
		turnRate(0.0),
		forwardRate(0.0)
	{ }

	Motion(Point2 current, float dirAtStart, Point2 before, Point2 end, float time, bool reversed) {
		/*Point2 directionPoint = current + Point2(dirAtStart);
		Point2 intersection = Point2::intersect(current, directionPoint, before, end);

		float distanceToTangent = (intersection - current).length();*/
		float distanceToGoal = (end - current).length();

		Point2 towardsLine = end - current;
		forwardRate = distanceToGoal / time * (reversed ? -1 : 1);
		turnRate = rsmall(towardsLine.Direction() - dirAtStart + (reversed ? r(180): 0)) / time;
	}

	float GetLeftSpeed(float width) {
		return forwardRate + turnRate*width;
	}

	float GetRightSpeed(float width) {
		return forwardRate - turnRate*width;
	}

	// Define a space where every point in that space will lead to the origin, and the 
};
