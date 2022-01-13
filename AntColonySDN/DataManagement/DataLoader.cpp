#include "DataLoader.h"

DataLoader::DataLoader(const std::string path)
{
	this->path = path;
}

DataLoader::DataLoader()
{
}

xml_document<>* DataLoader::LoadXml()
{
	std::string* rawData = new std::string(LoadFile(path));
	xml_document<>* doc = new xml_document<>();
	doc->parse<0>(&(*rawData)[0]);
	return doc;
}

xml_document<>* DataLoader::LoadXml(std::string path)
{
	std::string* rawData = new std::string(LoadFile(path));
	xml_document<>* doc = new xml_document<>();
	doc->parse<0>(&(*rawData)[0]);
	return doc;
}


std::string DataLoader::LoadFile(std::string path)
{

	std::ifstream indata(path);
	if (!indata)
		throw std::runtime_error("Couldn't open file");

	std::stringstream buffer;
	buffer << indata.rdbuf();
	return buffer.str();
}


