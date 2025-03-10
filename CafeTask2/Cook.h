//#pragma once
//#include "Order.h"
//#include <memory>
//
//class Cook
//{
//
//public:
//	Cook();
//	Cook(int salary, double productivityRate);
//	bool isBusy();
//	void setFree();
//	double getSalary();
//	std::shared_ptr<Order> getOrder();
//	void proceedCooking();
//	void assignOrder(const std::shared_ptr<Order> order);
//	
//
//private:
//	std::shared_ptr<Order> m_assignedOrder = nullptr;
//	double m_salary;
//	double m_productivityRate;
//};