#include "Link.h"

Link::Link()
{
	this->capacity = 0;
	this->cost = 0;
	this->current_traffic = MIN_TRAFFIC;
	this->exist_in_cost_path = 0;
}

Link::Link(float capacity, float cost)
{
	this->capacity = capacity;
	this->cost = cost;
	this->current_traffic = MIN_TRAFFIC;
	this->exist_in_cost_path = false;
}
