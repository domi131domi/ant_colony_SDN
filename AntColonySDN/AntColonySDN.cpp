#include <iostream>
#include "DataManagement/DataLoader.h"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"
#include "Time.h"
#include "AntColonyAlgorithm/Ant.h"
#include <fstream>
#include <chrono>

int main()
{
	std::string start = "Freiburg";
	std::string destination = "Flensburg";

	std::string name_of_test = "dummy";

	int printing = 50;				// defines number of saved records
	int iterate = 200;				// defines a step of algorithm between saving records
	int iters = printing * iterate;	// all iters of algorithm
	std::string root_folder = "path/to/test/folder/";
	std::string result_filename_scores = root_folder +
		start + "-" + destination + "\\" + name_of_test +
		"scores_" +
		"iters" + std::to_string(iters) + "_" +
		"Xw" + std::to_string(X_WEIGHT) + "_" +
		"Yw" + std::to_string(Y_WEIGHT) + "_" +
		"PHw" + std::to_string(PHEROMONE_WEIGHT) +
		"MAX_T" + std::to_string(MAX_COST) +
		".txt";

	std::string result_filename_paths = root_folder + 
		start + "-" + destination + "\\" + name_of_test +
		"paths_" +
		"iters" + std::to_string(iters) + "_" +
		"Xw" + std::to_string(X_WEIGHT) + "_" +
		"Yw" + std::to_string(Y_WEIGHT) + "_" +
		"PHw" + std::to_string(PHEROMONE_WEIGHT) +
		"MAX_T" + std::to_string(MAX_COST) +
		".txt";

	try
	{
		std::fstream result_file_scores;
		std::fstream result_file_paths;
		result_file_scores.open(result_filename_scores, std::ios::out | std::ios::trunc);
		result_file_paths.open(result_filename_paths, std::ios::out | std::ios::trunc);

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

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		for (int i = 0; i < printing; i++)
		{
			algorithm.Iterate(iterate, network->nodes[start], network->nodes[destination], network);
			std::chrono::steady_clock::time_point end_of_epoch = std::chrono::steady_clock::now();
			//std::cout << "Best score: " << algorithm.bestScore << std::endl;
			result_file_paths << "Best score: " << algorithm.bestScore << std::endl;
			result_file_scores 
				<< algorithm.bestScore 
				<< "," + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end_of_epoch - begin).count()) 
				<< std::endl;

			//std::cout << "Best path Ants: " << algorithm.bestPathX[0]->id;
			result_file_paths << "Best path Ants: " << algorithm.bestPathX[0]->id;
			for (int i = 1; i < algorithm.bestPathX.size(); i++)
			{
				//std::cout << " -> " << algorithm.bestPathX[i]->id;
				result_file_paths << " -> " << algorithm.bestPathX[i]->id;
			}

			result_file_paths << std::endl;
			result_file_paths << "Best path Dijkstra: " << algorithm.bestPathY[algorithm.bestPathY.size() - 1]->id;
			for (int i = 1; i < algorithm.bestPathY.size(); i++)
			{
				result_file_paths << " -> " << algorithm.bestPathY[algorithm.bestPathY.size() - i - 1]->id;
			}
			result_file_paths << "Finding this way took " + 
				std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end_of_epoch - begin).count()) 
				<< "[s]" << std::endl;
		}

		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		
		std::cout << "Algorithm finished after " + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(end - begin).count()) << "[s]" << std::endl;
		
			/*for (int i = 0; i < odwiedzoned.size(); i++) {
			std::cout << odwiedzoned[i]->id << std::endl;
		}*/
		result_file_scores.close();
		result_file_paths.close();
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
