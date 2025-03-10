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
	m_cafe->clearResult();
	for (double time = 0, endTime = m_workingHours * 60; time < endTime; time += m_timeInterval * 60)
	{
		m_cafe->serveClients(time);
		int numberNewClients = rand() % 11;/// generate some unmber fom 0 to getFreeSpaces;
		while (numberNewClients-- > 0 && m_cafe->getFreeSpaces() > 0)
		{
			m_cafe->placeNewClient(ClientFactory::getNewClient(time, m_cafe->getMenu()));
		}
		m_cafe->distributeOrders(time);
	}
	return m_cafe->getResult();
}


