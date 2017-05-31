#pragma once
#include "Item.h"
#include <memory>
#include <string>

enum class Change
{
	itemPurchased,
	deposit,
	withdraw
};

class Transaction
{
public:
	// Create transaction based on amount before and after
	Transaction(float amountBefore, float amountAfter, std::string name = std::string());

	// Create transaction based on amount before and an item
	Transaction(float amountBefore, Item item, std::string name = std::string());

	// Create transaction based on amount before and unique_ptr to item
	Transaction(float amountBefore, std::unique_ptr<Item> item, std::string name = std::string());

	// Sets name of transaction;
	template <typename Name>
	void setName(Name&& newName)
	{
		name = std::forward<Name>(newName);
	}

	// Returns name of the transaction
	std::string getName() const;

	// Returns amount before the transaction
	float getAmountBefore() const;

	// Returns amount after the transaction
	float getAmountAfter() const;

	// Returns change in balance due to transaction
	float getChangeInBalance() const;

	// Returns string of information about transaction
	std::string toString();

private:
	std::string name;
	float amountBefore;
	float changeInBalance;
	float amountAfter;
	Change typeOfTransaction;
	std::unique_ptr<Item> itemPurchased;
};