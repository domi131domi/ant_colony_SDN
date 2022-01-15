#include "AntColonyAlgorithm.h"
#include "Ant.h"

void AntColonyAlgorithm::Iterate(unsigned iterations,Node* start, Node* destination, NetworkStructure* network)
{
	for (unsigned iterationCounter = 0; iterationCounter < iterations; iterationCounter++)
	{
		for (unsigned antCounter = 0; antCounter < ColonySize; antCounter++)
		{

		}
	}
}

void AntColonyAlgorithm::ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network)
{
	Ant ant(start, destination);
	while (ant.Move()) {}
}

AntColonyAlgorithm::AntColonyAlgorithm(unsigned ColonySize) : ColonySize(ColonySize) {}

std::vector<Node*>::iterator AntColonyAlgorithm::findSmallestUnvisited(std::vector<Node*>& nodes, std::map<Node*, DataTable> data)
{
	auto res = nodes.begin(); float min = data[*res].minimum_distance;

	auto iterator = nodes.begin();
	while (iterator != nodes.end())
	{
		if (data[*res].minimum_distance < 0)
			res = iterator;
		else
			if (data[*iterator].minimum_distance >= 0 && data[*iterator].minimum_distance < data[*res].minimum_distance)
				res = iterator;
		iterator++;
	}
	return res;
}

std::map<Node*, DataTable> AntColonyAlgorithm::findDjikstraPath(Node* start, NetworkStructure* network)
{
	std::map<Node*, DataTable> data;
	std::vector<Node*> unvisited, visited;	//trzeba przerobic na heap bo tak jest O(n^2)

	for (auto &node : network->nodes)
	{
		data[node.second].minimum_distance = -1;
		data[node.second].previous_node = nullptr;
		unvisited.push_back(node.second);
	}
	data[start].minimum_distance = 0;

	while(unvisited.size() > 0)
	{
		std::vector<Node*>::iterator min = findSmallestUnvisited(unvisited, data);
		for (std::pair<Node*,Link> link : (*min)->links)
		{
			float current_distance = data[*min].minimum_distance + link.second.current_traffic;
			if (data[link.first].minimum_distance < 0 || data[link.first].minimum_distance > current_distance)
			{
				data[link.first].minimum_distance = current_distance;
				data[link.first].previous_node = *min;
			}
		}
		unvisited.erase(min);
	}

	return data;
}
