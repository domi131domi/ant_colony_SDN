#include "Link.h"

Link::Link()
{
	this->capacity = 0;
	this->usage_percentage = 0;
	this->current_usage = 0;
	this->cost = MIN_COST;
	this->exist_in_cost_path = false;
	this->pheromone = 0;
}

Link::Link(float capacity, float cost)
{
	this->capacity = capacity;
	this->usage_percentage = 0;		// current_usage / capacity
	this->current_usage = 0;
	this->cost = cost;				// current_traffic
	this->exist_in_cost_path = false;
	this->pheromone = 0;
}
