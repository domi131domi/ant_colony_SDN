#pragma once
#include<stdexcept>
#include "../DataManagement/Node.h"
#include <set>
#include <random>
#include "Utils.hpp"

class Ant
{
	Node* start;
	Node* destination;
	bool movingForward;
	std::vector<Node*> path;
public:
	bool Move();
	float CalculateHeuristic(Link link);
	Node* ChooseLink(Node* current_node);
	Ant(Node* start, Node* destination);
};

