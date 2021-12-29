#include <iostream>
#include "DataManagement/DataLoader.h"

int main()
{
    std::cout << "Witaj projekcie!\n";

	DataLoader loader("C:/Users/dominik.szacilowski/Desktop/POP/ant_colony_SDN/AntColonySDN/Resources/germany50.xml");
	loader.LoadXml();
}
