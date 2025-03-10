#pragma once
#include "Client.h"

class TolerantClient : public Client
{
public:
	TolerantClient(double time, std::shared_ptr<Order> order) : Client(time, order) { m_toleranceRate = NORMAL_TOLERANCE_RATE; };

	double getTolerance() override
	{
		return getOrder()->getCookingTime() * m_toleranceRate;
	}
};


