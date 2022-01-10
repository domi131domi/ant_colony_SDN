#pragma once

class Node;

class Link
{
public:
	Node* destination;
	float capacity;
	float cost;
	bool exist_in_cost_path;
	Link(Node* destination, float capactiy, float cost);
};

