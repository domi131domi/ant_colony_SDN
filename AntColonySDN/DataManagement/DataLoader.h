#pragma once
#include <string>
#include "RAPIDXML/rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace rapidxml;

class DataLoader
{
public:
	DataLoader(const std::string path);
	DataLoader();
	void LoadXml();
private:
	std::string path;
	std::string rawData;

	void LoadFile();
};

