#pragma once
#include <vector>
#include <string>
#include "Link.h"
#include <map>

class Node
{
public:
	std::string id;
	std::map<Node*, Link> links;
	Node(std::string id);
};

