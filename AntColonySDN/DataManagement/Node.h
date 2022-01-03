#pragma once
#include <vector>
#include <string>
#include "Link.h"

class Node
{
public:
	std::string id;
	std::vector<Link> links;
	Node(std::string id);
};

