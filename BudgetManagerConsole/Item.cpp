#include "Item.h"

using namespace std;

Item::Item(string name, float cost)
	: name(name),
	cost(cost)
{

}

string Item::getName() const
{
	return name;
}

void Item::setCost(float newCost)
{
	if (newCost <= 0)
	{
		return;
	}
	else
	{
		cost = newCost;
	}
}

float Item::getCost() const
{
	return cost;
}