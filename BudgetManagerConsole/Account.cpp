#include "Account.h"

using namespace std;

Account::Account(string name, float balance)
	: name(name),
	balance(balance)
{

}

string Account::getName() const
{
	return name;
}

void Account::setBalance(float newBalance)
{
	balance = newBalance;
}

float Account::getBalance() const
{
	return balance;
}

void Account::addFunds(float amount)
{
	// Checks for negative amount removed
	if (amount <= 0)
	{
		return;
	}
	balance += amount;
}

void Account::deductFunds(float amount)
{
	// Checks for overdraw or negative amount
	if (amount <= 0 || (balance - amount) < 0)
	{
		return;
	}
	else
	{
		balance -= amount;
	}
}

void Account::purchaseItem(unique_ptr<Item> purchase)
{
	balance -= purchase->getCost();
	itemsPurchased.push_back(move(purchase));
}

void Account::purchaseItem(Item purchase)
{
	unique_ptr<Item> item;
	item.reset(new Item(purchase));
	balance -= item->getCost();
	itemsPurchased.push_back(move(item));
}

//string Account::getHistory()
//{
	
//}