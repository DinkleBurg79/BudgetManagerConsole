#include "Account.h"

using namespace std;

Account::Account(string name, float balance)
	: name(name),
	balance(balance)
{

}

Account::Account(Account&& rhs)
	: name(move(rhs.name)),
	balance(move(rhs.balance)),
	history(move(rhs.history))
{

}

Account& Account::operator=(Account&& rhs)
{
	// If addresses of both objects are same, then return object
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		name = move(rhs.name);
		balance = move(rhs.balance);
		history = move(rhs.history);
		return *this;
	}
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

void Account::purchaseItem(unique_ptr<Item> purchase, string name)
{
	// Checks if cost of item is more than balance
	if (purchase->getCost() > balance)
	{
		return;
	}
	else
	{
		// Make unique_ptr<Transaction> to store information about this transaction,
		// and store this UPtr into history
		auto purchaseUPtr = make_unique<Transaction>(balance, move(purchase), name);
		balance -= purchaseUPtr->getChangeInBalance();
		// Update balance
		history.push_back(move(purchaseUPtr));
	}
}

unique_ptr<Transaction>& Account::editTransaction(int index)
{
	return history[index];
}

string Account::getHistoryOfDepositsAndWithdraws()
{
	string historyOfPurchases{};
	for (auto itr = history.begin(), end = history.end(); itr != end; ++itr)
	{
		// Iterate through history and check type of transaction for deposits,
		// and withdraws. Then append string to include string information about
		// the Transaction. Include two new line escape sequences for other deposits
		// or withdraws, and for a blank line.
		switch ((*itr)->getTypeOfTransaction())
		{
		case Change::deposit:
			historyOfPurchases += (*itr)->toString();
			historyOfPurchases += "\n\n";
			break;
		case Change::withdraw:
			historyOfPurchases += (*itr)->toString();
			historyOfPurchases += "\n\n";
			break;
		default:
			break;
		}
	}
	return historyOfPurchases;
}

string Account::getHistoryOfPurchases()
{
	string historyOfPurchases{};
	// Iterate through history and check type of transaction for item purchases.
	// Then append string to include string information about the Transaction.
	// Include two new line escape sequences for other item purchases, and for 
	// a blank line.
	for (auto itr = history.begin(), end = history.end(); itr != end; ++itr)
	{
		switch ((*itr)->getTypeOfTransaction())
		{
		case Change::itemPurchased:
			historyOfPurchases += (*itr)->toString();
			historyOfPurchases += "\n\n";
			break;
		default:
			break;
		}
	}
	return historyOfPurchases;
}

string Account::getHistory()
{
	string historyString{};
	// Iterate through history and append string to include information on
	// deposits, withdraws, or item purchases. Include two new line escape
	// sequences for other Transactions and for a blank line.
	for (auto itr = history.begin(), end = history.end(); itr != end; ++itr)
	{
		historyString += (*itr)->toString();
		historyString += "\n\n";
	}
	return historyString;
}