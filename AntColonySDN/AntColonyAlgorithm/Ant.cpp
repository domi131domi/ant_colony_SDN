#include "Ant.h"

bool Ant::Move()
{ 
	Node* current_node = start;
	while (current_node != destination)
	{

	}
	//return current == start
	return false;
}

float Ant::CalculateHeuristic(Link link)
{
	return 0.0f;
}

Ant::Ant(Node* start, Node* destination) : start(start), destination(destination) {}
