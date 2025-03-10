#pragma once
#include <vector>
#include "Dish.h"

class Order
{
public:
	Order() {};
	~Order() 
	{ 
		//m_dishes->clear();
	};
	void startCooking(double time);
	double getCookingTime();
	inline std::vector<Dish*>* const getDishes() { return m_dishes; };
	double getCookingStartTime();
	bool isReady(double time);
	double getCost();

	bool isClientLeft = false;

private:
	double m_cookingStartTime = -1;
	std::vector<Dish*>* m_dishes = new std::vector<Dish*>();
};

