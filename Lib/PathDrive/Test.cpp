#include "RobotSim.h"
#include "PathBuilder.h"
#include "PathNode.h"
#include "PathPlan.h"
#include "Point2.h"
#include "Motion.h"
#include <iostream>

int main() {
	PathBuilder builder;
	
	/* Test Pattern 1
	builder.AddNode(PathNode(Point2( 100, 0  ), r(0), 50, 50.0));
	builder.AddNode(PathNode(Point2( 200, 0  ), r(0), 50, 100.0));
	builder.AddNode(PathNode(Point2( 400, 0  ), r(0), 50, 100.0));
	builder.AddNode(PathNode(Point2( 500, 0  ), r(0), 50, 100.0));
	builder.AddNode(PathNode(Point2( 600, 100), r(90), 50, 100.0));
	builder.AddNode(PathNode(Point2( 500, 200), r(180), 50, 100.0));
	builder.AddNode(PathNode(Point2( 400, 300), r(180), 50, 100.0));
	builder.AddNode(PathNode(Point2( 200, 300), r(180), 100, 100.0));
	builder.AddNode(PathNode(Point2( 100, 200), r(180), 50, 100.0));
	builder.AddNode(PathNode(Point2( 0  , 100), r(270), 50, 100.0));
	builder.AddNode(PathNode(Point2( 100, 0  ), r(0), 50, 100.0));
	// */
	/* Test 2
	builder.AddNode(PathNode(Point2( 0  , 100), r(0), 50, 10.0));
	builder.AddNode(PathNode(Point2( 100, 0  ), r(270), 50, 300.0));
	builder.AddNode(PathNode(Point2( 0  ,-100), r(180), 50, 300.0));
	builder.AddNode(PathNode(Point2(-100, 0  ), r(90), 50, 300.0));
	builder.AddNode(PathNode(Point2( 0  , 100), r(0), 50, 300.0));
	builder.AddNode(PathNode(Point2( 100, 200), r(90), 50, 300.0));
	builder.AddNode(PathNode(Point2( 0  , 300), r(180), 50, 300.0));
	builder.AddNode(PathNode(Point2(-100, 200), r(270), 50, 300.0));
	builder.AddNode(PathNode(Point2( 0  , 100), r(0), 50, 300.0));
	builder.AddNode(PathNode(Point2( 500, 100), r(-45), 50, 200.0));
	builder.AddNode(PathNode(Point2( 800, 100), r(45), 50, 10.0));
	// */
	///* LeftSideScoreSwitch
	builder.AddNode(PathNode(Point2( 0  , 0  ), r(0), 50, 10.0));
	builder.AddNode(PathNode(Point2( 50, 0  ), r(0), 50, 200.0));
	builder.AddNode(PathNode(Point2( 120, 0  ), r(0), 50, 100.0));
	builder.AddNode(PathNode(Point2( 168, 60 ), r(90), 20, 40.0));
	// */
	///* LeftSideSwitchToCube
	builder.AddNodeReversed(PathNode(Point2( 168, 0 ), r(90), 10, 40.0));
	builder.AddNode(PathNode(Point2( 220, 0 ), r(0), 50, 40.0));
	builder.AddNode(PathNode(Point2( 220, 50 ), r(180), 20, 40.0));
	builder.AddNode(PathNode(Point2( 200, 50 ), r(180), 0, 20.0));
	// */
	///* LeftSideCubeToScale
	builder.AddNodeReversed(PathNode(Point2( 250, 50 ), r(180), 10, 40.0));
	// */

	PathPlan plan = builder.Plan();
	RobotSim sim = RobotSim(Point2(0, 0), r(0), 40);

	std::cout << "let nan = NaN\nlet points = [";
	sim.PrintState();
	
	int Iterations = 0;
	while(!plan.IsDone() && Iterations++ < 10000) {
		float deltaTime = 0.05;
		Motion motion = plan.GetNextPoint(
				sim.PredictedCentre(),
				sim.Direction(),
				deltaTime);
		sim.SimPos(motion, deltaTime);

		sim.PrintState();
	}
	std::cout << "]\nctx.strokeStyle='green'\nctx.fillStyle='green'\ndrawRobotPath(points)\n";
}
