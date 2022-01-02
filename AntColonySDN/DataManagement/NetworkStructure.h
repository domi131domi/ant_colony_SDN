#pragma once
#include <map>
#include "Node.h"
#include <string>

class NetworkStructure
{
	std::map<std::string, Node*> nodes;
	~NetworkStructure();

};

