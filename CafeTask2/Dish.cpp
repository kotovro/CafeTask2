#include "Dish.h"

Dish::Dish()
{
	m_cookingTime = 0;
}

Dish::Dish(std::vector<Ingredient*>* ingredients, const double cookingTime)
{
	std::vector<Ingredient*>* temp = ingredients;
	m_ingredients = temp;	
	m_cookingTime = cookingTime;
}

double Dish::getTotalPrice()
{
	double totalPrice = 0;
	for (Ingredient* ingredient : *m_ingredients)
		totalPrice += ingredient->getCost();
	return totalPrice;
}