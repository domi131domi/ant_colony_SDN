#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <map>
#include "../DataManagement/Node.h"
#include "../DataManagement/NetworkStructure.h"
#define MAX_TRAFFIC 3000

class Utils
{
public:


	struct DataTable
	{
		float minimum_distance;
		Node* previous_node;
	};

	static std::vector<Node*>::iterator findSmallestUnvisited(std::vector<Node*>& nodes, std::map<Node*, DataTable> data)
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

	static std::map<Node*, DataTable> findDjikstraPaths(Node* start, NetworkStructure* network, std::vector<Node*> pathX)
	{
		std::map<Node*, DataTable> data;
		std::vector<Node*> unvisited, visited;	//trzeba przerobic na heap bo tak jest O(n^2)

		for (auto& node : network->nodes)
		{
			data[node.second].minimum_distance = -1;
			data[node.second].previous_node = nullptr;
			unvisited.push_back(node.second);
		}
		data[start].minimum_distance = 0;

		while (unvisited.size() > 0)
		{
			std::vector<Node*>::iterator min = findSmallestUnvisited(unvisited, data);
			for (std::pair<Node*, Link> link : (*min)->links)
			{
				float traffic = link.second.cost;
				if (find(pathX.begin(), pathX.end(), link.first) != pathX.end())
					traffic += MAX_TRAFFIC;

				float current_distance = data[*min].minimum_distance + traffic;
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

	static float costFunction(float pathYPoints, float yWeight, float pathXPoints, float xWeight)
	{
		return 1/((yWeight / pathYPoints) + xWeight*(exp(pathXPoints)));
	}

	
	static std::vector<Node*> createPath(std::map<Node*, Utils::DataTable> map, Node* start, Node* destination)
	{
		std::vector<Node*> result;

		Node* current = destination;
		while (current != start)
		{
			result.push_back(current);
			current = map[current].previous_node;
		}
		result.push_back(current);
		return result;
	}
};
#endif // !1

