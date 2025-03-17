#include "pch.h"
#include "CppUnitTest.h"
#include "../CafeTask2/Dish.h"
#include "../CafeTask2/Dish.cpp"
#include "../CafeTask2/Order.h"
#include "../CafeTask2/Order.cpp"
#include "../CafeTask2/Menu.h"
#include "../CafeTask2/Menu.cpp"
#include "../CafeTask2/Cafe.h"
#include "../CafeTask2/Cafe.cpp"
#include "../CafeTask2/Client.h"
#include "../CafeTask2/Client.cpp"
#include "../CafeTask2/LowTolerantClient.h"
#include "../CafeTask2/SuperTolerantClient.h"
#include "../CafeTask2/TolerantClient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CafeUnitTests
{
	TEST_CLASS(CafeUnitTests)
	{
	public:
		
		TEST_METHOD(ServeClientWhoStayed)
		{
			Ingredient* ingredientForTests = new Ingredient(10);
			Dish* dish = new Dish();
			dish->getIngeredients()->push_back(ingredientForTests);
			dish->setCookingTime(3);
			std::shared_ptr<Order> order(new Order);
			order->getDishes()->push_back(dish);

			Menu* menu = new Menu();
			menu->getBreakfastMenu()->push_back(dish);

			Cafe* cafe = new Cafe(1, 1, 1, menu);
			LowTolerantClient *client = new LowTolerantClient(0, order);
			cafe->placeNewClient(client);
			cafe->distributeOrders(0);
			cafe->serveClients(4);
			
			Assert::AreEqual(0, cafe->getBusyCooks());
			
			delete cafe;
			delete menu;
			delete dish;
			delete ingredientForTests;
		}

		TEST_METHOD(PlaceNewClient)
		{
			Ingredient* ingredientForTests = new Ingredient(10);
			Dish* dish = new Dish();
			dish->getIngeredients()->push_back(ingredientForTests);
			std::shared_ptr<Order> order(new Order);
			order->getDishes()->push_back(dish);

			Menu* menu = new Menu();
			menu->getBreakfastMenu()->push_back(dish);

			Cafe* cafe = new Cafe(1, 1, 1, menu);
			LowTolerantClient* client = new LowTolerantClient(0, order);
			cafe->placeNewClient(client);

			Assert::AreEqual(0, cafe->getFreeSpaces());
			Assert::AreEqual(0, cafe->getBusyCooks());
			Assert::AreEqual(1, cafe->getTotalAmountOfOrders());

			delete cafe;
			delete menu;
			delete dish;
			delete ingredientForTests;
		}

		TEST_METHOD(DistributeOrdersAllCooksBusy)
		{
			Ingredient* ingredientForTests = new Ingredient(10);
			Dish* dish = new Dish();
			dish->getIngeredients()->push_back(ingredientForTests);
			std::shared_ptr<Order> order1(new Order);
			order1->getDishes()->push_back(dish);
			std::shared_ptr<Order> order2(new Order);
			order2->getDishes()->push_back(dish);

			Menu* menu = new Menu();
			menu->getBreakfastMenu()->push_back(dish);

			Cafe* cafe = new Cafe(2, 1, 1, menu);
			LowTolerantClient* client1 = new LowTolerantClient(0, order1);
			cafe->placeNewClient(client1);
			LowTolerantClient* client2 = new LowTolerantClient(0, order2);
			cafe->placeNewClient(client2);
			cafe->distributeOrders(2);

			Assert::AreEqual(0, cafe->getFreeSpaces());
			Assert::AreEqual(1, cafe->getBusyCooks());
			Assert::AreEqual(1, cafe->getTotalAmountOfOrders());

			delete cafe;
			delete menu;
			delete dish;
			delete ingredientForTests;
		}
		
		TEST_METHOD(ClientLeaveTest)
		{
			Ingredient* ingredientForTests = new Ingredient(10);
			Dish* dish = new Dish();
			dish->getIngeredients()->push_back(ingredientForTests);
			dish->setCookingTime(3);
			std::shared_ptr<Order> order(new Order);
			order->getDishes()->push_back(dish);

			Menu* menu = new Menu();
			menu->getBreakfastMenu()->push_back(dish);

			Cafe* cafe = new Cafe(1, 0, 1, menu);
			LowTolerantClient* client = new LowTolerantClient(0, order);
			cafe->placeNewClient(client);
			cafe->serveClients(40); 

			Assert::AreEqual(1, cafe->getFreeSpaces());
			Assert::AreEqual(0, cafe->getBusyCooks());
			
			delete cafe;
			delete menu;
			delete dish;
			delete ingredientForTests;
		}

	};
}
