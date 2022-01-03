#pragma once

class Node;

class Link
{
public:
	Node* destination;
	float capacity;
	float cost;
	Link(Node* destination, float capactiy, float cost);
};

