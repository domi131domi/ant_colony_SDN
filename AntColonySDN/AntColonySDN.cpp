#include <iostream>
#include "DataManagement/DataLoader.h"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"

int main()
{
	try
	{
		std::cout << "Witaj projekcie!\n";

		DataLoader loader("../AntColonySDN/Resources/germany50.xml");
		NetworkStructure* network = new NetworkStructure(loader.LoadXml());
		network->ApplyTraffic(loader.LoadXml("../AntColonySDN/Resources/traffic.xml"));

		AntColonyAlgorithm algorithm(5);
		//auto result = algorithm.findDjikstraPath(network->nodes["Aachen"], network);
		algorithm.Iterate(2, network->nodes["Giessen"], network->nodes["Fulda"], network);

	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
