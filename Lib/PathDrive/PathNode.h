#pragma once
#include "Point2.h"

class PathNode {
public:
	Point2 pos;
	Point2 dir;
	float speed;

	PathNode(Point2 pos, float angle, float weight, float speed):
		pos(pos),
		dir(weight * Point2(angle)),
		speed(speed)
	{
		printf("ctx.strokeStyle='red'\n");
		printf("drawVec(%f, %f, %f, %f)\n", pos.x, pos.y, pos.x + dir.x, pos.y + dir.y);
	}
};
