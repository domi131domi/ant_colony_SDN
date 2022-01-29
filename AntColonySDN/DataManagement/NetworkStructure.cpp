#include "NetworkStructure.h"

NetworkStructure::NetworkStructure(xml_document<>* doc)
{
	try
	{
		xml_node<>* xml_network = doc->first_node("network");
		xml_node<>* xml_network_structure = xml_network->first_node("networkStructure");
		LoadNodes(xml_network_structure);
		LoadLinks(xml_network_structure);
	}
	catch (std::exception ex)
	{
		throw new std::logic_error("Xml file cannot be read properly with message: " + std::string(ex.what()));
	}
}

void NetworkStructure::ApplyTraffic(xml_document<>* doc)
{
	try
	{
		xml_node<>* xml_traffic_list = doc->first_node("traffic_list");
		xml_node<>* current_traffic = xml_traffic_list->first_node();
		while (current_traffic != 0 && strcmp(current_traffic->name(), "traffic") == 0)
		{
			std::string source = current_traffic->first_node("source")->value();
			std::string target = current_traffic->first_node("target")->value();
			std::string trafficValueString = current_traffic->first_node("value")->value();
			float demandValue = std::stof(trafficValueString);

			nodes[source]->links[nodes[target]].current_traffic = demandValue;
			nodes[target]->links[nodes[source]].current_traffic = demandValue;
			current_traffic = current_traffic->next_sibling();
		}
		//delete xml_traffic_list;
		//delete doc->first_node("traffic_list");
	}
	catch(std::exception ex)
	{
		throw new std::logic_error("Xml file cannot be read properly with message: " + std::string(ex.what()));
	}
}

void NetworkStructure::LoadLinks(rapidxml::xml_node<>* xml_structure)
{
	xml_node<>* xml_links = xml_structure->first_node("links");
	xml_node<>* current_link = xml_links->first_node();
	while (current_link != 0 && strcmp(current_link->name(), "link") == 0)
	{
		std::string source = current_link->first_node("source")->value();
		std::string target = current_link->first_node("target")->value();
		xml_node<>* addModule = current_link->first_node("additionalModules")->first_node("addModule");
		std::string string_capacity(addModule->first_node("capacity")->value());
		std::string string_cost(addModule->first_node("cost")->value());
		float capacity = std::stof(string_capacity);
		float cost = std::stof(string_cost);

		Link link(capacity, cost);
		nodes[source]->links[nodes[target]] = link;
		nodes[target]->links[nodes[source]] = link;
		current_link = current_link->next_sibling();
	}
}

void NetworkStructure::LoadNodes(rapidxml::xml_node<>* xml_structure)
{
	xml_node<>* xml_nodes = xml_structure->first_node("nodes");
	xml_node<>* current_node = xml_nodes->first_node();
	while (current_node != 0 && strcmp(current_node->name(), "node") == 0)
	{
		std::string id = current_node->first_attribute("id")->value();
		nodes[id] = new Node(id);
		current_node = current_node->next_sibling();
	}
}

NetworkStructure::~NetworkStructure()
{
	std::map<std::string, Node*>::iterator it;

	for (it = this->nodes.begin(); it != this->nodes.end(); it++)
	{
		delete it->second;
		//delete 
	}
}
