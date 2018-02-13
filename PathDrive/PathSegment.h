#pragma once
#include "PathNode.h"
#include "Bezier.h"

class PathSegment {
private:
	std::shared_ptr<PathNode> start;
	std::shared_ptr<PathNode> end;

public:
	Bezier curve;
	bool reversed;

	PathSegment(std::shared_ptr<PathNode> _start, std::shared_ptr<PathNode> _end, bool _reversed):
		start(_start),
		end(_end),
		reversed(_reversed)
	{
		if(reversed) {
			curve = Bezier(start->pos, start->pos - start->dir, end->pos + end->dir, end->pos);
		} else {
			curve = Bezier(start->pos, start->pos + start->dir, end->pos - end->dir, end->pos);
		}
	}

	float GetSpeedAt(float t) {
		return (1.0 - t) * start->speed + t * end->speed;
	}
};
