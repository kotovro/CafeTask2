#pragma once
#include <iostream>

struct Result
{
	int servedClients = 0;
	int leavingClients = 0;
	double income = 0;
	double loss = 0;

	inline void clearResult()
	{
		servedClients = 0;
		leavingClients = 0;
		income = 0;
		loss = 0;
	}
};

inline std::ostream& operator<<(std::ostream& Str, Result const& res) 
{
	Str << "Served clients: " << res.servedClients << std::endl
		<< "Clients left cafe: " << res.leavingClients << std::endl
		<< "Total income: " << res.income << std::endl
		<< "Totoal loss: " << res.loss << std::endl;
	return Str;
}



