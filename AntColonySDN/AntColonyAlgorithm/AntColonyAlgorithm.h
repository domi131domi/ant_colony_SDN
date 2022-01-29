#pragma once
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <map>
#include "../DataManagement/Node.h"
#include "../DataManagement/NetworkStructure.h"
#include "Ant.h"

class AntColonyAlgorithm
{
public:
	unsigned ColonySize = 1;

	void Iterate(unsigned iterations, Node* start, Node* destination, NetworkStructure* network);
	void ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network);
	AntColonyAlgorithm(unsigned ColonySize);
	float bestScore = -1;
	std::vector<Node*> bestPathX;
	std::vector<Node*> bestPathY;
};

