#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "DataManagement/DataLoader.h"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"
#include "Time.h"


BOOST_AUTO_TEST_SUITE(unitTests)

BOOST_AUTO_TEST_CASE(myTestCase)
{
  BOOST_TEST(1 == 1);
  BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(memoryLeaksTest)
{
	std::cout << "Witaj projekcie!\n";
	srand(time(NULL));
	DataLoader loader("../AntColonySDN/Resources/simpleExampleNetwork.xml");
	std::pair<xml_document<>*, std::string*> doc1 = loader.LoadXml();
	//xml_document<>* doc = loader.LoadXml();
	NetworkStructure* network = new NetworkStructure(doc1.first);
	std::pair<xml_document<>*, std::string*> doc2 = loader.LoadXml("../AntColonySDN/Resources/simpleExampleTraffic.xml");
	network->ApplyTraffic(doc2.first);

	AntColonyAlgorithm algorithm(5);
	algorithm.Iterate(1000, network->nodes["A"], network->nodes["E"], network);

	std::cout << "Best score: " << algorithm.bestScore << std::endl;

	std::cout << "Best path x: " << algorithm.bestPathX[0]->id;
	for (int i = 1; i < algorithm.bestPathX.size(); i++)
	{
		std::cout << " -> " << algorithm.bestPathX[i]->id;
	}
	std::cout << std::endl;
	std::cout << "Best path y: " << algorithm.bestPathY[algorithm.bestPathY.size() - 1]->id;
	for (int i = 1; i < algorithm.bestPathY.size(); i++)
	{
		std::cout << " -> " << algorithm.bestPathY[algorithm.bestPathY.size() - i - 1]->id;
	}
	doc1.first->clear();
	doc2.first->clear();
	delete doc1.first;
	delete doc1.second;
	delete doc2.first;
	delete doc2.second;
	delete network;
}

BOOST_AUTO_TEST_SUITE_END()