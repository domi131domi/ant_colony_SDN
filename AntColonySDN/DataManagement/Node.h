#pragma once
#include <vector>
#include <string>
#include <map>
#include "Link.h"

class Node
{
public:
	std::string id;
	std::map<Node*, Link> links;
	Node(std::string id);
};

