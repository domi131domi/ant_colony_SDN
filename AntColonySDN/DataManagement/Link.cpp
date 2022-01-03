#include "Link.h"

Link::Link(Node* destination, float capacity, float cost)
{
	this->destination = destination;
	this->capacity = capacity;
	this->cost = cost;
}
