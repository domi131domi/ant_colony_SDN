#pragma once

class Node;
const float MIN_TRAFFIC = 0.001;

class Link
{
public:
	float capacity;
	float cost;
	float current_traffic;
	bool exist_in_cost_path;
	Link();
	Link(float capactiy, float cost);
};

