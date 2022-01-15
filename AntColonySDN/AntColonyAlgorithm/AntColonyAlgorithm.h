#pragma once
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <map>
#include "../DataManagement/Node.h"
#include "../DataManagement/NetworkStructure.h"

struct DataTable
{
	float minimum_distance;
	Node* previous_node;
};

class AntColonyAlgorithm
{
public:
	unsigned ColonySize = 1;

	void Iterate(unsigned iterations, Node* start, Node* destination, NetworkStructure* network);
	void ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network);
	AntColonyAlgorithm(unsigned ColonySize);
	std::vector<Node*>::iterator findSmallestUnvisited(std::vector<Node*>& nodes, std::map<Node*, DataTable> data);
	std::map<Node*, DataTable> findDjikstraPath(Node* start, NetworkStructure* network);
};

