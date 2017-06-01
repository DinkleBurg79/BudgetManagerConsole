#include "Transaction.h"
#include <iostream>

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
	cout << "not move constructor" << endl;
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
	cout << "not move constructor" << endl;
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
	cout << "not move constructor" << endl;
}

string Transaction::getName() const
{
	return name;
}

Change Transaction::getTypeOfTransaction() const
{
	return typeOfTransaction;
}

//void Transaction::setItemPurchased(Item item)
//{
	// Create unique_ptr<Item> of item
	//auto purchasedItem = make_unique<Item>(item);
	//if (item.getCost() < amountBefore)
	//{
		//switch (typeOfTransaction)
		//{
		//case Change::itemPurchased:
			// Switch previous item with new purchased item
			//itemPurchased = move(purchasedItem);
			// Update amountAfter with cost of new item
			//changeInBalance = itemPurchased->getCost();
			//amountAfter = amountBefore - changeInBalance;
			//break;
		//case Change::deposit:
			// Instantiate itemPurchasd with item
			//itemPurchased = move(purchasedItem);
			//changeInBalance = itemPurchased->getCost();
			//amountAfter = amountBefore - changeInBalance;
			//typeOfTransaction = Change::itemPurchased;
			//break;
		//case Change::withdraw:
			//itemPurchased = move(purchasedItem);
			//changeInBalance = itemPurchased->getCost();
			//amountAfter = amountBefore - changeInBalance;
			//typeOfTransaction = Change::itemPurchased;
			//break;
		//}
	//}
	//else
	//{
		//return;
	//}
//}

void Transaction::setItemPurchased(unique_ptr<Item> item)
{
	if (item->getCost() < amountBefore)
	{
		switch (typeOfTransaction)
		{
		case Change::itemPurchased:
			// Switch previous item with new purchased item
			itemPurchased = move(item);
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			break;
		case Change::deposit:
			itemPurchased = move(item);
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			break;
		case Change::withdraw:
			itemPurchased = move(item);
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			break;
		}
	}
	else
	{
		return;
	}
}

void Transaction::setAmountBefore(float amount)
{
	// Checks if amount is negative
	if (amount <= 0)
	{
		return;
	}
	else
	{
		// Update amountBefore, changeInBalance, and typeOfTransaction
		amountBefore = amount;
		changeInBalance = amountAfter - amountBefore;
		// Checks if type of transaction is deposit or withdraw
		if (changeInBalance < 0)
		{
			typeOfTransaction = Change::withdraw;
		}
		else 
		{
			typeOfTransaction = Change::deposit;
		}
	}
}

float Transaction::getAmountBefore() const
{
	return amountBefore;
}

void Transaction::setAmountAfter(float amount)
{
	// Checks if amount if negative
	if (amount <= 0)
	{
		return;
	}
	else
	{
		// Update amountAfter, changeInBalance, and typeOfTransaction
		amountAfter = amount;
		changeInBalance = amountAfter - amountBefore;
		// Checks if type of transaction is deposit or withdraw
		if (changeInBalance < 0)
		{
			typeOfTransaction = Change::withdraw;
		}
		else
		{
			typeOfTransaction = Change::deposit;
		}
	}
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
	string transaction{};
	switch (typeOfTransaction)
	{
	case Change::deposit:
		transaction += "Deposit\n";
		break;
	case Change::withdraw:
		transaction += "Withdraw\n";
		break;
	case Change::itemPurchased:
		transaction += "Item Purchased\n";
		break;
	default:
		break;
	}
	transaction += "Description: ";
	transaction += name + "\nAmount Before: ";
	transaction += to_string(amountBefore);
	transaction += "\nAmount After: ";
	transaction += to_string(amountAfter);
	transaction += "\nChange in balance: ";
	transaction += to_string(changeInBalance);
	
	switch (typeOfTransaction)
	{
	case Change::itemPurchased:
		transaction += "\nItem purchased: " + itemPurchased->getName();
		transaction += "\nCost: " + to_string(itemPurchased->getCost());
		break;
	default:
		break;
	}
	return transaction;
}