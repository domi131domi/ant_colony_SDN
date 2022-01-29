#include "DataLoader.h"

DataLoader::DataLoader(const std::string path)
{
	this->path = path;
}

DataLoader::DataLoader()
{
}


std::pair<xml_document<>*, std::string*> DataLoader::LoadXml()
{
	std::pair<xml_document<>*, std::string*> outcome;
	std::string* rawData = new std::string(LoadFile(path));
	xml_document<>* doc = new xml_document<>();
	doc->parse<0>(&(*rawData)[0]);
	outcome.first = doc;
	outcome.second = rawData;
	return outcome;
}

std::pair<xml_document<>*, std::string*> DataLoader::LoadXml(std::string path)
{
	std::pair<xml_document<>*, std::string*> outcome;
	std::string* rawData = new std::string(LoadFile(path));
	xml_document<>* doc = new xml_document<>();
	doc->parse<0>(&(*rawData)[0]);
	outcome.first = doc;
	outcome.second = rawData;
	return outcome;
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


