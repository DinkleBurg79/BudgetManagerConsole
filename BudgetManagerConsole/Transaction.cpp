#include "Transaction.h"

using namespace std;

Transaction::Transaction(float amountBefore, float amountAfter, string name)
	: name(name),
	amountBefore(amountBefore),
	amountAfter(amountAfter)
{
	changeInBalance = amountAfter - amountBefore;
	if (amountAfter < 0 || amountBefore < 0)
	{
		changeInBalance = 0;
	}
	else if (changeInBalance < 0)
	{
		typeOfTransaction = Change::withdraw;
	}
	else
	{
		typeOfTransaction = Change::deposit;
	}
}

Transaction::Transaction(float amountBefore, Item item, string name)
	: name(name),
	amountBefore(amountBefore)
{
	itemPurchased.reset(new Item(item));
	changeInBalance = itemPurchased->getCost();
	if (changeInBalance < 0 || (amountBefore - changeInBalance) < 0)
	{
		changeInBalance = 0;
	}
	else
	{
		typeOfTransaction = Change::itemPurchased;
		amountAfter = amountBefore - changeInBalance;
	}
}

Transaction::Transaction(float amountBefore, unique_ptr<Item> item, string name)
	: name(name),
	amountBefore(amountBefore)
{
	itemPurchased = move(item);
	changeInBalance = itemPurchased->getCost();
	if (changeInBalance < 0 || (amountBefore - changeInBalance) < 0)
	{
		changeInBalance = 0;
	}
	else
	{
		typeOfTransaction = Change::itemPurchased;
		amountAfter = amountBefore - changeInBalance;
	}
}

string Transaction::getName() const
{
	return name;
}

float Transaction::getAmountBefore() const
{
	return amountBefore;
}

float Transaction::getAmountAfter() const
{
	return amountAfter;
}

float Transaction::getChangeInBalance() const
{
	return changeInBalance;
}

string Transaction::toString()
{
	string transaction{ "Name: " };
	transaction += name + "\nAmount Before: ";
	transaction += to_string(amountBefore);
	transaction += "\nAmount After: ";
	transaction += to_string(amountAfter);
	transaction += "\nChange in balance: ";
	transaction += to_string(changeInBalance);
	
	if (typeOfTransaction == Change::itemPurchased)
	{
		transaction += "\nItem purchased: " + itemPurchased->getName();
		transaction += "\nCost: " + to_string(itemPurchased->getCost());
	}
	return transaction;
}