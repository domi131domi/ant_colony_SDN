#include "Node.h"
#include <iostream>

int globalCounter = 1;

Node::Node(std::string id)
{
	this->id = id;
}

Node::~Node()
{

	// jakiekolwiek odniesienie do this skutkuje wyjebaniem stackoverflow

	//std::map<Node*, Link>::iterator it;
	//std::cout << globalCounter++ << " ";
	//std::cout << this->links.size() << std::endl;

	/*for (it = this->links.begin(); it != this->links.end(); it++)
	{
		delete it->first;
	}
	std::cout << "checkpoint" << std::endl;*/

}
