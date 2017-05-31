#pragma once
#include <string>

class Item
{
public:
	// Constructor with optional params for name and cost
	Item(std::string name = std::string(), float cost = 0.0f);

	// Sets name of item
	template <typename Name>
	void setName(Name&& newName)
	{
		name = std::forward<Name>(newName);
	}

	// Returns name through const getter
	std::string getName() const;

	// Sets cost of item
	void setCost(float newCost);

	// Returns cost of item through const getter
	float getCost() const;

private:
	std::string name;
	float cost;
};