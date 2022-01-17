#include "Ant.h"

bool Ant::Move()
{ 
	Node* current_node = start;

	if (movingForward)
	{
		if (current_node != destination)
		{
			Node* chosen = ChooseLink(current_node);
			path.push_back(current_node);
			current_node = chosen;
		}
		else
		{
			
			movingForward = false;
		}
	}
	else
	{

	}
	//return current == start
	return false;
}

float Ant::CalculateHeuristic(Link link)
{
	return link.cost * 1 / link.pheromone;
}

Node* Ant::ChooseLink(Node* current_node)
{
	float sumHeuristic = 0;
	std::map<Node*, float> heuristics;
	for (auto& link : current_node->links)
	{
		if (find(path.begin(), path.end(), link.first) == path.end())
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

Ant::Ant(Node* start, Node* destination) : start(start), destination(destination), movingForward(true) {}
