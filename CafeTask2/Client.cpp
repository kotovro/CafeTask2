#include "Client.h"

Client::Client(double time, std::shared_ptr<Order> order) : m_order(order)
{
	m_entranceTime = time;
}

Client::Client(const Client& otherClient) : m_order(otherClient.getOrder())
{
	m_entranceTime = otherClient.getEntarnceTime();
}

double Client::getEntarnceTime() const
{
	return m_entranceTime;
}

std::shared_ptr<Order> Client::getOrder() const
{
	return m_order;
}

Client::~Client()
{

}
