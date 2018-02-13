#pragma once
#include <cmath>


class Point2;
Point2 operator * (float s, Point2 const& point);

class Point2 {
public:
	Point2(float _x, float _y): x(_x), y(_y) {
	}

	Point2(float angle):
		x(cos(angle)),
		y(sin(angle))
	{
	}

	float x;
	float y;

	Point2 operator + (Point2 const& other) const {
		return Point2(x + other.x, y + other.y);
	}

	Point2 operator - (Point2 const& other) const {
		return Point2(x - other.x, y - other.y);
	}

	float dot(Point2 const& other) const {
		return x * other.x + y * other.y;
	}

	float length() {
		return sqrt(squaredLength());
	}

	float squaredLength() {
		return x*x + y*y;
	}

	Point2 normalize() {
		float len = length();
		if(len != 0.0) {
			return Point2(x/len, y/len);
		} else {
			return Point2(0.0, 0.0);
		}
	}

	static Point2 intersect(Point2 a1, Point2 a2, Point2 b1, Point2 b2) {
		float x43 = b2.x-b1.x;
		float y43 = b2.y-b1.y;
		float x21 = a2.x-a1.x;
		float y21 = a2.y-a1.y;
		float x31 = b1.x-a1.x;
		float y31 = b1.y-a1.y;

		float s = (x43*y31-x31*y43) / (x43*y21-x21*y43);
		return (s*(a2-a1)) + a1;
	}

	float Direction() {
		return atan2(y, x);
	}
};

Point2 operator * (float s, Point2 const& point) {
	return Point2(s * point.x, s * point.y);
}

float r(float deg) {
	return deg * (M_PI / 180.0);
}
