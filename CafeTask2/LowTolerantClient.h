#pragma once
#include "Client.h"

class LowTolerantClient : public Client
{
public:
	LowTolerantClient(double time, std::shared_ptr<Order> order) : Client(time, order) { m_toleranceRate = LOW_TOLERANCE_RATE; };

	double getTolerance() override
	{
		return getOrder()->getCookingTime() * m_toleranceRate + 5.0 / 60;
	}
};


