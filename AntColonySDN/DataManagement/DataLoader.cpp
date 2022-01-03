#include "DataLoader.h"

DataLoader::DataLoader(const std::string path)
{
	this->path = path;
}

DataLoader::DataLoader()
{
}

NetworkStructure* DataLoader::LoadXml()
{
	LoadFile();

	xml_document<> doc;
	doc.parse<0>(&rawData[0]);
	return new NetworkStructure(&doc);
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


