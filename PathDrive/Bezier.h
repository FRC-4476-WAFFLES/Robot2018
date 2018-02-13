#pragma once
#include <functional>
#include "Point2.h"

class Bezier {
public:
	Bezier():
		p0(0.0), p1(0.0), p2(0.0), p3(0.0)
	{
	}
	Bezier(Point2 _p0, Point2 _p1, Point2 _p2, Point2 _p3): 
		p0(_p0),
		p1(_p1),
		p2(_p2),
		p3(_p3)
	{
		printf("p0 = {x: %f, y: %f}\n", p0.x, p0.y);
		printf("p1 = {x: %f, y: %f}\n", p1.x, p1.y);
		printf("p2 = {x: %f, y: %f}\n", p2.x, p2.y);
		printf("p3 = {x: %f, y: %f}\n", p3.x, p3.y);
		printf("\nctx.strokeStyle='blue'\ndrawBezier([p0, p1, p2, p3])\n");
	}

	Bezier Reversed() {
		return Bezier(p3, p2, p1, p0);
	}

	Point2 At(float t) {
		float nt = 1.0 - t; // nt is (t-1)
		float nt2 = nt*nt; // nt2 is (t-1) squared
		float t2 = t*t; // t2 is t squared

		return
			(  nt2*nt) * p0 +
			(3*nt2*t ) * p1 +
			(3*nt *t2) * p2 +
			(  t  *t2) * p3;
	}

	float MoveAheadBy(float t, float targetDistance, Point2 startPoint) {
		float mix = MinimizeT([&] (float mixt) {
			return fabs((At(mixt * (1.0-t) + t) - startPoint).length() - targetDistance);
		});
		return mix * (1.0-t) + t;
	}

	float FindClosest(Point2 target) {
		return MinimizeT([&] (float t) {
			return (At(t) - target).length();
		});
	}

	float MinimizeT(std::function<float(float)> func) { 
		// Do an initial search at 2^INITIAL_SCAN points.
		float tnew;
		float tscore = 10000000.0;
		float step = exp2(float(-(INITIAL_SCAN)));
		for(int i=1; i<(2<<(INITIAL_SCAN-1)); i++) {
			float t = float(i)*step;
			float score = func(t);
			if(score < tscore) {
				tnew = t;
				tscore = score;
			}
		}

		// Find the local minimum starting from the initial point
		for(int i=INITIAL_SCAN+1; i<MAX_DEPTH; i++) {
			float delta = exp2(float(-i));
			float pt = tnew + delta;
			float nt = tnew - delta;
			float ps = func(pt);
			float ns = func(nt);

			if(ps < ns) {
				tnew = pt;
				tscore = ps;
			} else {
				tnew = nt;
				tscore = ns;
			}
		}

		return tnew;
	}

private:
	Point2 p0;
	Point2 p1;
	Point2 p2;
	Point2 p3;

	// The maximum number of iterations for finding a point
	static constexpr int MAX_DEPTH = 7;

	// 2^INITIAL_SCAN points on the segment are tested before using
	// normal descent from the best of those tested.
	static constexpr int INITIAL_SCAN = 3;
};
