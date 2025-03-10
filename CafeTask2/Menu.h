#pragma once
#include <vector>
#include <iostream>
#include "Dish.h" 


class Menu
{
public:
	Menu() {};

	inline std::vector<Dish*>* getBreakfastMenu() { return m_breakfast;	}

	inline std::vector<Dish*>* getLunchMenu() {	return m_lunch; }
	
	inline std::vector<Dish*>* getDinnerMenu() { return m_dinner; }

	inline std::vector<Dish*>* getDrinksMenu() {	return m_drinks; }

	inline std::vector<Dish*>* getCocktailsMenu() {	return m_cocktails; }

	
	~Menu()
	{
		
		std::cout << "Menu is destroyed!" << std::endl;
		delete m_breakfast;
		delete m_lunch;
		delete m_dinner;
		delete m_drinks;
		delete m_cocktails;
		std::cout << "Submenus are destroyed!" << std::endl;
	}

private:
	std::vector<Dish*> *m_breakfast = new std::vector<Dish*>();
	std::vector<Dish*> *m_lunch = new std::vector<Dish*>();
	std::vector<Dish*> *m_dinner = new std::vector<Dish*>();
	std::vector<Dish*> *m_drinks = new std::vector<Dish*>();
	std::vector<Dish*> *m_cocktails = new std::vector<Dish*>();
};

