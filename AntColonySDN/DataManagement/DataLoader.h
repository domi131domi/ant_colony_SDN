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

	// zwracana para wskaŸników ze wzglêdu na poŸniejsz¹ koniecznoœæ zwolnienia pamiêci
	std::pair<xml_document<>*, std::string*> LoadXml();
	std::pair<xml_document<>*, std::string*> LoadXml(std::string path);
	
private:
	std::string path;
	std::string LoadFile(std::string path);
};

