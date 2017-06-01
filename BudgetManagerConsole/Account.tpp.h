#pragma once
#include "Account.h"

template <typename Name>
void Account::setName(Name&& newName)
{
	name = std::forward<Name>(newName);
}

template <typename Amount, typename Name>
void Account::addFunds(Amount amount, Name&& name)
{
	// Checks for negative amount added in
	if (amount <= 0)
	{
		return;
	}
	else
	{
		// Make unique_ptr<Transaction> to store information about this transaction,
		// and store this UPtr into history
		auto deposit = std::make_unique<Transaction>(balance, balance + amount, std::forward<Name>(name));
		history.push_back(std::move(deposit));
		// Update balance
		balance += amount;
	}
}

template <typename Amount, typename Name = std::string>
void Account::deductFunds(Amount amount, Name&& name)
{
	// Checks for overdraw or negative amount deducted
	if (amount <= 0 || (balance - amount) < 0)
	{
		return;
	}
	else
	{
		// Make unique_ptr<Transaction> to store information about this transaction,
		// and store this UPtr into history
		auto withdraw = std::make_unique<Transaction>(balance, balance - amount, std::forward<Name>(name));
		history.push_back(move(withdraw));
		// Update balance
		balance -= amount;
	}
}

template <typename Item, typename Name>
void Account::purchaseItem(Item&& purchase, Name&& name)
{
	// Checks if cost of item is more than balance
	if (purchase.getCost() > balance)
	{
		return;
	}
	else
	{
		// Make unique_ptr<Transaction> to store information about this transaction,
		// and store this UPtr into history
		auto purchaseUPtr = std::make_unique<Transaction>(balance, std::forward<Item>(purchase), std::forward<Name>(name));
		balance -= purchaseUPtr->getChangeInBalance();
		// Update balance
		history.push_back(std::move(purchaseUPtr));
	}
}