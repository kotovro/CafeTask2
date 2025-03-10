#pragma once
#include "Order.h"
#include <memory>
#define LOW_TOLERANCE_RATE  1;
#define SUPER_TOLERANCE_RATE  10;
#define NORMAL_TOLERANCE_RATE  2;


class Client
{

public:
	Client() {};
	Client(double time, std::shared_ptr<Order> order);
	Client(const Client& otherClient);
	virtual ~Client();
	std::shared_ptr<Order> getOrder() const;
	virtual double getTolerance() = 0;
	double getEntarnceTime() const;
	

private:
	std::shared_ptr<Order> m_order;
	double m_entranceTime;

protected:
	double m_toleranceRate = -1;
};

