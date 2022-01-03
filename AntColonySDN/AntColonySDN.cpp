#include <iostream>
#include "DataManagement/DataLoader.h"

int main()
{
	try
	{
		std::cout << "Witaj projekcie!\n";

		DataLoader loader("../AntColonySDN/Resources/germany50.xml");
		NetworkStructure* network = loader.LoadXml();


	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
