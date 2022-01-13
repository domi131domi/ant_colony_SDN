#pragma once
#include <string>
#include "RAPIDXML/rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "NetworkStructure.h"

using namespace rapidxml;

class DataLoader
{
public:
	DataLoader(const std::string path);
	DataLoader();
	xml_document<>* LoadXml();
	xml_document<>* LoadXml(std::string path);
	
private:
	std::string path;

	std::string LoadFile(std::string path);
};

