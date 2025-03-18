#pragma once
#include "Cafe.h"
#include "ClientFactory.h"

class Simulation
{
public:
	Simulation();
	Simulation(int cafeCapacity, int cooksCount, double cooksSalary,  double workingTime, double timeInterval, Menu* const menu);
	~Simulation();
	Result simulateDay();

private:	
	Cafe* m_cafe;
	double m_timeInterval;
	double m_workingHours;
};

