#pragma once
#include "Client.h"

class SuperTolerantClient : public Client
{
public:
	SuperTolerantClient(double time, std::shared_ptr<Order> order) : Client(time, order) { m_toleranceRate = SUPER_TOLERANCE_RATE; };
	~SuperTolerantClient() {};
	double getTolerance() override
	{
		return getOrder()->getCookingTime() * m_toleranceRate;
	}
};


