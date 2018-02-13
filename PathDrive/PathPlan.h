#pragma once
#include <vector>
#include "PathSegment.h"
#include "Motion.h"

class PathPlan {
private:
	std::vector<PathSegment> segments;
	unsigned int current_segment;
	float last_t;

public:
	PathPlan(std::vector<PathSegment> segs):
		segments(segs),
		current_segment(0),
		last_t(0)
	{
	}

	float GetClosestT(Point2 currentPos) {
		if(IsDone()) {
			return 0.0;
		}
		
		float t = segments[current_segment].curve.FindClosest(currentPos);
		if(t < last_t) {
			t = last_t;
		}
		last_t = t;

		if(t >= 0.97) {
			printf("// end of segment %d\n", current_segment);
			current_segment++;
			last_t = 0.0;
			return GetClosestT(currentPos);
		}

		return t;
	}

	float NextT(float t, float distance, Point2 currentPos) {
		if(IsDone()) {
			return 0.0;
		}

		PathSegment& current = segments[current_segment];
		float new_t = current.curve.MoveAheadBy(t, distance, currentPos);

		return new_t;
	}

	Motion GetNextPoint(Point2 currentPos, float currentDir, float nextTimeEstimate) {
		// Don't move if we're finished the path
		if(IsDone()) {
			return Motion();
		}

		float closest = GetClosestT(currentPos);
		if(IsDone()) {
			return Motion();
		}
		int closest_seg = current_segment;
		float lookahead = 10.0;
		float lookaheadTime = lookahead*nextTimeEstimate;
		float speed = segments[closest_seg].GetSpeedAt(closest);
		float distance = speed*lookaheadTime;
		printf("// %f\n", closest);

		float next = NextT(closest, distance, currentPos);
		Point2 before = segments[closest_seg].curve.At(next-0.01);
		Point2 end = segments[closest_seg].curve.At(next);

		float realTime = (end - currentPos).length()/speed;

		return Motion(currentPos, currentDir, before, end, realTime, segments[closest_seg].reversed);
	}

	bool IsDone() {
		return current_segment >= segments.size();
	}
};
