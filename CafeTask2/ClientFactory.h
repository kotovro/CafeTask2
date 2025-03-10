#pragma once
#include <vector>
#include <memory>
#include "Client.h"
#include "Menu.h"

class ClientFactory
{
public:
	inline static bool isWanted() { return rand() % 2 > 0; }
	inline static void addDishToOrder(std::vector<Dish*>* menuPart, std::shared_ptr<Order> order)
	{
		int dishIndex = rand() % menuPart->size();
		order->getDishes()->push_back(menuPart->at(dishIndex));
	}
	static Client* getNewClient(double time, Menu* const menu);
};

