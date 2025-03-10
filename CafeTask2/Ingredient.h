#pragma once
class Ingredient
{
public:
	Ingredient(double cost) { m_cost = cost; }
	inline double getCost() { return m_cost; };
private:
	double m_cost;
};