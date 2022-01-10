#pragma once
#include <map>
#include "Node.h"
#include <string>
#include "RAPIDXML/rapidxml.hpp"
#include <stdexcept>

using namespace rapidxml;

class NetworkStructure
{
public:
	std::map<std::string, Node*> nodes;
	NetworkStructure(xml_document<>* doc);
	~NetworkStructure();

};

