#include <algorithm>
#include <iterator>
#include <memory>
#include <iostream>
#include "Cafe.h"

Cafe::Cafe(int capacity, int cooksCount, double cooksSalary, Menu* menu)
{
	m_cooks = cooksCount;
	m_capacity = capacity;
	m_menu = menu;
	m_cookSalary = cooksSalary;
}

Cafe::~Cafe()
{
	delete m_orders;
	delete m_clients;
}

void Cafe::serveClients(double time)
{
	auto clientsToLeave = std::partition(m_clients->begin(), m_clients->end(), [time](Client* client) {
		return !client->getOrder()->isReady(time);
	});

	for (auto servedClient = clientsToLeave; servedClient != m_clients->end(); ++servedClient)
	{
		//std::shared_ptr<Order> order = servedClient->getOrder();
		m_result.income += (*servedClient)->getOrder()->getCost() + (*servedClient)->getOrder()->getCookingTime() * m_cookSalary;
		//std::cout << "Cook got:" << (*servedClient)->getOrder()->getCookingTime() * m_cookSalary << std::endl;
		delete (*servedClient);
		m_result.servedClients++;
		m_busyCooks--;
	}
	m_clients->erase(clientsToLeave, m_clients->end());
	

	clientsToLeave = std::partition(m_clients->begin(), m_clients->end(), [time](Client* client) {
		return time <= (client->getEntarnceTime() + client->getTolerance());
	});

	for (auto clientToLeave = clientsToLeave; clientToLeave != m_clients->end(); ++clientToLeave)
	{
		if ((*clientToLeave)->getOrder()->getCookingStartTime() >= 0)
		{
			m_result.loss += (*clientToLeave)->getOrder()->getCost();
			m_result.loss += (time - (*clientToLeave)->getOrder()->getCookingStartTime()) * m_cookSalary;
			m_busyCooks--;
		}
		(*clientToLeave)->getOrder()->isClientLeft = true;
		m_result.leavingClients++;
		delete (*clientToLeave);
		//std::cout << "Client left!" << std::endl;
	}
	m_clients->erase(clientsToLeave, m_clients->end());
}

void Cafe::restartCafe() 
{
	m_clients->clear();
	while (!m_orders->empty())
		m_orders->pop();
	m_busyCooks = 0;
	m_result.clear();
}

Result Cafe::getResult()
{	
	return m_result;
}

void Cafe::distributeOrders(double time)
{
	if (m_orders->empty() || m_busyCooks == m_cooks)
	{
		return;
	}

	for (int cookIndex = 0, freeCooks = m_cooks - m_busyCooks; cookIndex != freeCooks; ++cookIndex)
	{
		while(m_orders->front()->isClientLeft)
			m_orders->pop();

		m_orders->front()->startCooking(time);
		m_orders->pop();

		m_busyCooks++;

		if (m_orders->empty())
		{
			break;
		}
	}
}

void Cafe::placeNewClient(Client* client)
{
	m_clients->push_back(client);
	m_orders->push(client->getOrder());
}