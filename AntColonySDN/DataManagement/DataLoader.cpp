#include "DataLoader.h"

DataLoader::DataLoader(const std::string path)
{
	this->path = path;
}

DataLoader::DataLoader()
{
}

void DataLoader::LoadXml()
{
	LoadFile();

	xml_document<> doc;
	doc.parse<0>(&rawData[0]);
	std::cout << doc.first_node()->name() << std::endl;
	std::cout << doc.first_node()->value() << std::endl;
	xml_node<> *structure = doc.first_node()->first_node();
	xml_node<> *nodes = structure->first_node("nodes");
	std::cout << nodes->name() << std::endl;
	std::cout << nodes->first_attribute()->name() << std::endl;
	std::cout << nodes->first_attribute()->value() << std::endl;
}

void DataLoader::LoadFile()
{

	std::ifstream indata(path);
	if (!indata)
		throw std::runtime_error("Couldn't open file");

	std::stringstream buffer;
	buffer << indata.rdbuf();
	rawData = buffer.str();
}


