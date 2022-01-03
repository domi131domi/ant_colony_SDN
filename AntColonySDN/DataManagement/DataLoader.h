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
	NetworkStructure* LoadXml();
private:
	std::string path;
	std::string rawData;

	void LoadFile();
};

