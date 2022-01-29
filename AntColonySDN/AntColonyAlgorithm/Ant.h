#pragma once
#include "Utils.h"
#include <stdexcept>
#include "../DataManagement/Node.h"
#include <set>
#include <random>
#include "../DataManagement/NetworkStructure.h"

class Ant
{
	Node* start;
	Node* destination;
	NetworkStructure* network;
	bool movingForward;
	float pathXpoints = 0;
	float pheromone = 0;
	int movingBackIterator = -1;
	Node* current_node;
public:
	bool Move();
	float CalculateHeuristic(Link link);
	Node* ChooseLink(Node* current_node);
	Ant(Node* start, Node* destination, NetworkStructure* network);
	std::vector<Node*> path;
	std::vector<Node*> pathY;
	float finalScore = 0;
	~Ant();
};

