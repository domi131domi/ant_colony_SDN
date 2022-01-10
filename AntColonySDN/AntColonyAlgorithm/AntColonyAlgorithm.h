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
	void Iterate(unsigned iterations);
	void MoveAnts();
	std::vector<Node*>::iterator findSmallestUnvisited(std::vector<Node*>& nodes, std::map<Node*, DataTable> data);
	std::map<Node*, DataTable> findDjikstraPath(Node* start, NetworkStructure* network);
};

