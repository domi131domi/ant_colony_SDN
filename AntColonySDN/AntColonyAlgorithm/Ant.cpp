#include "Ant.h"
#include <cmath>
#include <iostream>

bool Ant::Move()
{

	if (current_node == start && !movingForward)
		return false;

	if (movingForward)
	{
		if (current_node != destination)
		{
			Node* chosen = ChooseLink(current_node);
			if (current_node == chosen)
				return false;
			path.push_back(current_node);
			pathXpoints += log(1 - current_node->links[chosen].usage_percentage);
			current_node = chosen;
		}
		else
		{
			std::map<Node*, Utils::DataTable> map = Utils::findDjikstraPaths(start, network, path);
			pathY = Utils::createPath(map, start, destination);
			float pathYPoints = map[destination].minimum_distance;
			finalScore = Utils::costFunction(pathYPoints, Y_WEIGHT, pathXpoints, X_WEIGHT);
			pheromone = finalScore;
			std::cout << pheromone << std::endl;
			movingForward = false;
		}
	}
	else
	{
		if (movingBackIterator < 0)
			movingBackIterator = path.size() - 1;
		Node* previous_node = path[movingBackIterator];
		previous_node->links[current_node].pheromone = std::max(previous_node->links[current_node].pheromone, pheromone);
		current_node = previous_node;
		movingBackIterator--;
	}

	return true;
}

float Ant::CalculateHeuristic(Link link)
{
	return (X_WEIGHT * link.usage_percentage + link.pheromone);
}

Node* Ant::ChooseLink(Node* current_node)
{
	float sumHeuristic = 0;
	std::map<Node*, float> heuristics;
	for (auto& link : current_node->links)
	{
		if (path.begin() != path.end() && find(path.begin(), path.end(), link.first) != path.end())
			continue;

		heuristics[link.first] = CalculateHeuristic(link.second);
		sumHeuristic += heuristics[link.first];
	}

	float random = (float)rand() / (float)RAND_MAX;

	float lastValue = 0;
	Node* last = current_node;
	for (auto& heuristic : heuristics)
	{
		float value = lastValue + (heuristic.second / sumHeuristic);
		lastValue = value;

		if (random <= value)
		{
			return heuristic.first;
		}

		last = heuristic.first;
	}

	return last;
}

Ant::Ant(Node* start, Node* destination, NetworkStructure* network) : start(start), destination(destination), movingForward(true), network(network), current_node(start) {}
