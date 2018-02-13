#pragma once
#include <vector>
#include <memory>
#include "PathNode.h"
#include "PathPlan.h"
#include "PathSegment.h"

class PathBuilder {
private:
	std::shared_ptr<PathNode> prev_node;
	std::vector<PathSegment> segments;

public:
	PathBuilder(): prev_node() {}

	void AddNode(PathNode node) {
		std::shared_ptr<PathNode> new_node = std::make_shared<PathNode>(node);
		if(prev_node.get() != nullptr) {
			segments.push_back(PathSegment(prev_node, new_node, false));
		}
		prev_node = new_node;
	}

	void AddNodeReversed(PathNode node) {
		std::shared_ptr<PathNode> new_node = std::make_shared<PathNode>(node);
		if(prev_node.get() != nullptr) {
			segments.push_back(PathSegment(prev_node, new_node, true));
		}
		prev_node = new_node;
	}

	PathPlan Plan() {
		return PathPlan(segments);
	}
};
