#include "Order.h"

void Order::startCooking(double time)
{
	m_cookingStartTime = time;
}

double Order::getCost()
{
	double totalCost = 0;
	for (auto dish : *m_dishes)
	{
		totalCost += dish->getTotalPrice();
	}
	return totalCost;
}

double Order::getCookingTime() const
{
	double totalCookingTime = 0;
	for (auto dish : *m_dishes)
	{
		totalCookingTime += dish->getCookingTime();
	}
	return totalCookingTime;
}

double Order::getCookingStartTime()  
{
	return m_cookingStartTime;
}

bool Order::isReady(double time) const
{
	return (m_cookingStartTime < 0 ) ? false : time >= m_cookingStartTime + getCookingTime();
}