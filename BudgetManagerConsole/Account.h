#pragma once
#include <string>

class Account
{
public:
	// Constructor for account with optional string param
	Account(std::string name = std::string(), float balance = 0.0f);

	// Sets name of account
	template <typename String>
	void setName(String&& newName)
	{
		name = std::forward<String>(newName);
	}

	// Returns name through const getter
	std::string getName() const;

	// Sets balance of account
	void setBalance(float newBalance);

	// Returns balance through const getter
	float getBalance() const;

	// Adds funds to balance
	void addFunds(float amount);

private:
	std::string name;
	float balance;
};