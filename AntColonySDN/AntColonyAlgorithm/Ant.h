#pragma once
#include<stdexcept>
#include "../DataManagement/Node.h"

class Ant
{
	Node* start;
	Node* destination;
public:
	bool Move();
	float CalculateHeuristic(Link link);
	Ant(Node* start, Node* destination);
};

