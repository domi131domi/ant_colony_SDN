#include "AntColonyAlgorithm.h"

void AntColonyAlgorithm::Iterate(unsigned iterations, Node* start, Node* destination, NetworkStructure* network)
{
	for (unsigned iterationCounter = 0; iterationCounter < iterations; iterationCounter++)
	{
		for (unsigned antCounter = 0; antCounter < ColonySize; antCounter++)
		{
			ProcessNewAnt(start, destination, network);
		}
		//EvaporatePheromone(network);
	}
}

void AntColonyAlgorithm::ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network)
{
	Ant ant(start, destination, network);
	while (ant.Move()) { ; }
	if (!ant.dead && (bestScore < 0 || bestScore > ant.finalScore))
	{
		bestScore = ant.finalScore;
		bestPathX = ant.path;
		bestPathX.push_back(destination);
		bestPathY = ant.pathY;
	}
}

void AntColonyAlgorithm::EvaporatePheromone(NetworkStructure* network)
{
	for (auto& node : network->nodes)
	{
		for (auto& link : node.second->links)
		{
			link.second.pheromone *= evaporation_percentage;
		}	
	}
}

AntColonyAlgorithm::AntColonyAlgorithm(unsigned ColonySize) : ColonySize(ColonySize) {}