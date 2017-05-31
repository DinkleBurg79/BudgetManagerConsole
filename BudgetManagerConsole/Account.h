#pragma once
#include "Item.h"
#include "Transaction.h"
#include <string>
#include <memory>
#include <vector>

class Account
{
public:
	// Constructor for account with optional string param
	Account(std::string name = std::string(), float balance = 0.0f);

	// Sets name of account
	template <typename Name>
	void setName(Name&& newName)
	{
		name = std::forward<Name>(newName);
	}

	// Returns name through const getter
	std::string getName() const;

	// Sets balance of account
	void setBalance(float newBalance);

	// Returns balance through const getter
	float getBalance() const;

	// Adds funds to balance
	void addFunds(float amount);

	// Remove funds from balance
	void deductFunds(float amount);

	// Adds item to history and deducts cost from balance
	void purchaseItem(std::unique_ptr<Item> purchase);

	// Adds item to history and deducts cost from balance
	void purchaseItem(Item purchase);

	// Returns history of account including all purchases/deposits/withdraws
	//std::string getHistory();

private:
	std::string name;
	float balance;
	// Keeps histroy of changes to account
	std::vector<std::unique_ptr<Transaction>> history;
	// List of items purchased
	std::vector<std::unique_ptr<Item>> itemsPurchased;
};