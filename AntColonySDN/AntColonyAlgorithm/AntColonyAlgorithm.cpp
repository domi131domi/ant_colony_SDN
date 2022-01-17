#include "AntColonyAlgorithm.h"
#include "Ant.h"

void AntColonyAlgorithm::Iterate(unsigned iterations,Node* start, Node* destination, NetworkStructure* network)
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
	Ant ant(start, destination);
	while (ant.Move()) {}
}

AntColonyAlgorithm::AntColonyAlgorithm(unsigned ColonySize) : ColonySize(ColonySize) {}