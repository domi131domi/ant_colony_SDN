#pragma once

class Node;
const float MIN_COST = 0.001;

class Link
{
public:
	float capacity;
	float current_usage;
	float usage_percentage;
	float cost;
	float pheromone;
	bool exist_in_cost_path;
	Link();
	Link(float capactiy, float cost);
};

