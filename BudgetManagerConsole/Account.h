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

	// Deleted copy constructor
	Account(const Account& rhs) = delete;

	// Deleted copy assignment operator
	Account& operator=(const Account& rhs) = delete;

	// Move constructor
	Account(Account&& rhs);

	// Move assignment operator
	Account& operator=(Account&& rhs);

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
	void addFunds(float amount, std::string name = std::string());

	// Remove funds from balance
	void deductFunds(float amount, std::string name = std::string());

	// Adds item to history and deducts cost from balance
	void purchaseItem(Item purchase, std::string name = std::string());

	// Adds item to history and deducts cost from balance
	void purchaseItem(std::unique_ptr<Item> purchase, std::string name = std::string());

	// Returns reference to unique_ptr<Transaction> to be edited
	std::unique_ptr<Transaction>& editTransaction();

	// Returns history of deposits and withdraws
	std::string getHistoryOfDepositsAndWithdraws();

	// Returns history of items bought
	std::string getHistoryOfPurchases();

	// Returns history of account including all purchases/deposits/withdraws
	std::string getHistory();

private:
	std::string name;
	float balance;
	// Keeps histroy of changes to account
	std::vector<std::unique_ptr<Transaction>> history;
	// List of items purchased
	//std::vector<std::unique_ptr<Item>> itemsPurchased;
};