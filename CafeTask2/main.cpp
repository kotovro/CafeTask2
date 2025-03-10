
#include <iostream>
#include "Simulation.h"
#include "SimulationInitializer.h"

int main()
{
	int daysCount;
	int cafeCapacity = 10;
	double workingTime = 13;
	int cooksCount = 5;
	double timeInterval = 1.0 / 60;
	double cookSalary = 10.2;
	std::map<std::string, Ingredient*>* ingredients = new std::map<std::string, Ingredient*>();
	std::map<std::string, Dish*>* dishes = new std::map<std::string, Dish*>();

	Menu* menu = new Menu();
	SimuationInitializer::initializeMenu(menu, 
		SimuationInitializer::initializeDishes(dishes, 
			SimuationInitializer::initializeIngredients(ingredients)));
	std::cout << "Enter total amount of days: ";
	std::cin >> daysCount;
	std::cout << std::endl;
	Simulation simulation(cafeCapacity, cooksCount, cookSalary, workingTime, timeInterval, menu);
	for (int day = 1; day <= daysCount; ++day)
	{
		std::cout << "Day " << day << ":" << std::endl;
		Result result = simulation.simulateDay();
		std::cout << result;
	}
	delete menu;
	SimuationInitializer::clearMenu(dishes, ingredients);

}