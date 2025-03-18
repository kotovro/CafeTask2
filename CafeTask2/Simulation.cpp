#include "Simulation.h"


Simulation::Simulation(int cafeCapacity, int cooksCount, double cookSalary, double workingHours,  double timeInterval, Menu* menu)
{
	m_timeInterval = timeInterval;
	m_workingHours = workingHours;
	m_cafe = new Cafe(cafeCapacity, cooksCount, cookSalary, menu);
}

Simulation::~Simulation()
{
	delete m_cafe;
}

Result Simulation::simulateDay()
{
	m_cafe->restartCafe();
	for (double time = 0; time < m_workingHours; time += m_timeInterval)
	{
		m_cafe->serveClients(time);
		int numberNewClients = rand() % 11;
		while (numberNewClients-- > 0 && m_cafe->getFreeSpaces() > 0)
		{
			m_cafe->placeNewClient(ClientFactory::getNewClient(time, m_cafe->getMenu()));
		}
		m_cafe->distributeOrders(time);
	}
	return m_cafe->getResult();
}


