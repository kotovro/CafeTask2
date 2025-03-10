#pragma once
#include <vector>
#include <list>
#include <queue>
#include "Client.h"
#include "Order.h"
#include "Cook.h"
#include "Result.h"
#include "Menu.h"

class Cafe
{
public:
	Cafe() {};
	Cafe(int capacity, int cooksCount, double cooksSalary, Menu *menu);
	~Cafe();
	void distributeOrders(double time);
	void serveClients(double time);
	void placeNewClient(Client* client);
	void restartCafe();
	Result getResult();
	inline Menu* const getMenu() { return m_menu; };
	inline int getFreeSpaces() const { return m_capacity - m_clients->size(); };

private:
	int m_capacity;
	double income = 0;
	double losses = 0;
	std::queue<std::shared_ptr<Order>>* m_orders = new std::queue<std::shared_ptr<Order>>();
	std::list<Client*>* m_clients = new std::list<Client*>();
	int m_cooks;
	double m_cookSalary;
	int m_busyCooks = 0;
	Result m_result;
	Menu* m_menu;
};

