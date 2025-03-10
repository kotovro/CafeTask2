#include <stdlib.h>
#include "ClientFactory.h"
#include "Dish.h"
#include "RandomUtil.h"
#include "LowTolerantClient.h"
#include "TolerantClient.h"
#include "SuperTolerantClient.h"

Client* ClientFactory::getNewClient(double time, Menu* const menu)
{
	bool isTimeIndependentStrategy = (rand() % 10) >= 8;
	std::shared_ptr<Order> order = std::make_shared<Order>();
	Client client();
	if (isTimeIndependentStrategy)
	{
		if (isWanted())
		{
			addDishToOrder(menu->getBreakfastMenu(), order);
		}

		if (isWanted())
		{
			addDishToOrder(menu->getLunchMenu(), order);
		}

		if (isWanted())
		{
			addDishToOrder(menu->getDinnerMenu(), order);
		}

		if (isWanted())
		{
			addDishToOrder(menu->getCocktailsMenu(), order);
		}

		if (isWanted())
		{
			addDishToOrder(menu->getDrinksMenu(), order);
		}
	}

	else
	{
		if ((int)time <= 5)
		{
			addDishToOrder(menu->getBreakfastMenu(), order);
			addDishToOrder(menu->getDrinksMenu(), order);
		}
		
		else if ((int)time <= 9)
		{
			addDishToOrder(menu->getDinnerMenu(), order);
		}

		else 
		{
			addDishToOrder(menu->getLunchMenu(), order);
			addDishToOrder(menu->getCocktailsMenu(), order);
		}
	}

	int clientRandom = rand() % 10;
	Client* resultClient = (clientRandom < 2) 
		? (Client*)new LowTolerantClient(time, order) 
		:	(clientRandom > 7)
			? (Client*)new SuperTolerantClient(time, order)
			: (Client*)new TolerantClient(time, order);

	return resultClient;
}