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
	if (amount <= 0)
	{
		return;
	}
	balance += amount;
}