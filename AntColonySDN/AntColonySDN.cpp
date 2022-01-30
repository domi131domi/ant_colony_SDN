#include <iostream>
#include "DataManagement/DataLoader.h"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"
#include "Time.h"
#include "AntColonyAlgorithm/Ant.h"

//std::vector<Node*> odwiedzoned;

int main()
{
	try
	{
		std::cout << "Witaj projekcie!\n";
		srand(time(NULL));
		//DataLoader loader("../AntColonySDN/Resources/simpleExampleNetwork.xml");
		DataLoader loader("../AntColonySDN/Resources/germany50.xml");
		std::pair<xml_document<>*, std::string*> doc1 = loader.LoadXml();;
		NetworkStructure* network = new NetworkStructure(doc1.first);
		//std::pair<xml_document<>*, std::string*> doc2 = loader.LoadXml("../AntColonySDN/Resources/simpleExampleTraffic.xml");
		std::pair<xml_document<>*, std::string*> doc2 = loader.LoadXml("../AntColonySDN/Resources/germany50traffic.xml");
		network->ApplyTraffic(doc2.first);

		AntColonyAlgorithm algorithm(5);
		//algorithm.Iterate(1000, network->nodes["A"], network->nodes["E"], network);
		for (int i = 0; i < 10; i++)
		{
			algorithm.Iterate(100, network->nodes["Freiburg"], network->nodes["Flensburg"], network);

			std::cout << "Best score: " << algorithm.bestScore << std::endl;

			std::cout << "Best path Ants: " << algorithm.bestPathX[0]->id;
			for (int i = 1; i < algorithm.bestPathX.size(); i++)
			{
				std::cout << " -> " << algorithm.bestPathX[i]->id;
			}
			std::cout << std::endl;
			std::cout << "Best path Dijkstra: " << algorithm.bestPathY[algorithm.bestPathY.size() - 1]->id;
			for (int i = 1; i < algorithm.bestPathY.size(); i++)
			{
				std::cout << " -> " << algorithm.bestPathY[algorithm.bestPathY.size() - i - 1]->id;
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < odwiedzoned.size(); i++) {
			std::cout << odwiedzoned[i]->id << std::endl;
		}
		doc1.first->clear();
		doc2.first->clear();
		delete doc1.first;
		delete doc1.second;
		delete doc2.first;
		delete doc2.second;
		delete network;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
