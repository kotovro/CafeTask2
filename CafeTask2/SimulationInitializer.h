#pragma once
#include <map>
#include <string>
#include <memory>
#include "Dish.h"
#include "Cafe.h"
#include "Ingredient.h"

class SimuationInitializer
{
public:
	static std::map<std::string, Ingredient*>* initializeIngredients(std::map<std::string, Ingredient*>* ingredients);
	static std::map<std::string, Dish*>* initializeDishes(std::map<std::string, Dish*>* dishes, std::map<std::string, Ingredient*>* ingredients);
	static Menu* initializeMenu(Menu* menu, std::map<std::string, Dish*>* dishes);
	static void clearMenu(std::map<std::string, Dish*>* dishes, std::map < std::string, Ingredient*>* ingredients);
};

