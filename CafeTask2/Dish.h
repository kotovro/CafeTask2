#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Ingredient.h"
#include <unordered_set>

class Dish
{
public:

	Dish();
	Dish(std::vector<Ingredient*>* ingredients, double cookingTime);
	~Dish(){}
	inline void setCookingTime(double cookingTime) { m_cookingTime = cookingTime; };
	std::vector<Ingredient*>*  getIngeredients() { return m_ingredients; };
	double getTotalPrice();
	double getCookingTime() { return m_cookingTime; };

private:
	std::vector<Ingredient*>* m_ingredients = new std::vector<Ingredient*>();
	double m_cookingTime = 0;
};