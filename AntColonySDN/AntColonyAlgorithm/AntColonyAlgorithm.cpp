#include "AntColonyAlgorithm.h"
#include <fstream>
#include <iostream>

void AntColonyAlgorithm::Iterate(unsigned iterations, Node* start, Node* destination, NetworkStructure* network)
{
	for (unsigned iterationCounter = 0; iterationCounter < iterations; iterationCounter++)
	{
		for (unsigned antCounter = 0; antCounter < ColonySize; antCounter++)
		{
			ProcessNewAnt(start, destination, network);
		}
		EvaporatePheromone(network);
	}
}

void AntColonyAlgorithm::ProcessNewAnt(Node* start, Node* destination, NetworkStructure* network)
{
	std::string tescik = "kazdy_Score";
	std::string root_folder = "C:\\Users\\adams\\Desktop\\pop\\wyniczki\\testy\\";
	std::string result_filename_scores = root_folder + tescik + ".txt";
	Ant ant(start, destination, network);
	while (ant.Move()) { ; }
	std::fstream all_scores_file;
	all_scores_file.open(result_filename_scores, std::ios::out | std::ios::app);
	if(!ant.dead && !(ant.finalScore > 5*bestScore))
		all_scores_file << ant.finalScore << std::endl;
	if (!ant.dead && (bestScore < 0 || bestScore > ant.finalScore))
	{
		bestScore = ant.finalScore;
		bestPathX = ant.path;
		bestPathX.push_back(destination);
		bestPathY = ant.pathY;
	}
	all_scores_file.close();
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