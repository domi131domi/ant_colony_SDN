#include "NetworkStructure.h"

NetworkStructure::NetworkStructure(xml_document<>* doc)
{
	try
	{
		xml_node<>* xml_structure = doc->first_node()->first_node();
		xml_node<>* xml_nodes = xml_structure->first_node("nodes");
		xml_node<>* current_node = xml_nodes->first_node();
		while (current_node != 0 && strcmp(current_node->name(), "node") == 0)
		{
			std::string id = current_node->first_attribute("id")->value();
			nodes[id] = new Node(id);
			current_node = current_node->next_sibling();
		}

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

			nodes[source]->links.push_back(Link(nodes[target], capacity, cost));
			nodes[target]->links.push_back(Link(nodes[source], capacity, cost));
			//czy to sa sieci dwukierunkowe ???? ^^^^
			current_link = current_link->next_sibling();
		}
	}
	catch (std::exception ex)
	{
		throw new std::logic_error("Xml file cannot be read properly.");
	}
}

NetworkStructure::~NetworkStructure()
{
	//clean map
}
