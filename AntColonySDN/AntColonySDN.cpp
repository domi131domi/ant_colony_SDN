#include <iostream>
#include "DataManagement/DataLoader.h"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"

int main()
{
	try
	{
		std::cout << "Witaj projekcie!\n";

		DataLoader loader("../AntColonySDN/Resources/germany50.xml");
		NetworkStructure* network = loader.LoadXml();

		AntColonyAlgorithm algorithm;
		auto result = algorithm.findDjikstraPath(network->nodes["Aachen"], network);

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
