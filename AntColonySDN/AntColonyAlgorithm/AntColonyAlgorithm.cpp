#include "AntColonyAlgorithm.h"

void AntColonyAlgorithm::Iterate(unsigned iterations)
{
	throw std::logic_error("Not implemented");
}

void AntColonyAlgorithm::MoveAnts()
{
	throw std::logic_error("Not implemented");
}

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

//naiwne w ... bardzo
std::map<Node*, DataTable> AntColonyAlgorithm::findDjikstraPath(Node* start, NetworkStructure* network)
{
	std::map<Node*, DataTable> data;
	std::vector<Node*> unvisited, visited;	//najlepiej przerobic na heap

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
		for (Link link : (*min)->links)
		{
			float current_distance = data[*min].minimum_distance + link.capacity;
			if (data[link.destination].minimum_distance < 0 || data[link.destination].minimum_distance > current_distance)
			{
				data[link.destination].minimum_distance = current_distance;
				data[link.destination].previous_node = *min;
			}
		}
		unvisited.erase(min);
	}

	return data;
}
