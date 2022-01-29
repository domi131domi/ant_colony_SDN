#include "AntColonyAlgorithm.h"
#include <iostream>

void AntColonyAlgorithm::Iterate(unsigned iterations, Node* start, Node* destination, NetworkStructure* network)
{
	for (unsigned iterationCounter = 0; iterationCounter < iterations; iterationCounter++)
	{
		for (unsigned antCounter = 0; antCounter < ColonySize; antCounter++)
		{
			ProcessNewAnt(start, destination, network);
		}
	}
}

void AntColonyAlgorithm::ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network)
{
	Ant ant(start, destination, network);
	while (ant.Move()) {;}
	if (bestScore < 0 || bestScore > ant.finalScore)
	{
		bestScore = ant.finalScore;
		bestPathX = ant.path;
		bestPathX.push_back(destination);
		bestPathY = ant.pathY;
	}
}

AntColonyAlgorithm::AntColonyAlgorithm(unsigned ColonySize) : ColonySize(ColonySize) {}

AntColonyAlgorithm::~AntColonyAlgorithm()
{

	//for (Node* path : bestPathX)
	//{
	//	if(path)
	//		path->~Node();
	//}
	//for (Node* path : bestPathY)
	//{
	//	if (path)
	//		path->~Node();
	//}
}
