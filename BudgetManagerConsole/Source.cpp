#include "Account.h"
#include <iostream>

using namespace std;

int main()
{
	Account a{};
	a.setName("Jean Valjean");
	a.setBalance(100);
	cout << a.getName() << endl;
	cout << a.getBalance() << endl;
	a.addFunds(-3);
	a.addFunds(40);
	cout << a.getBalance() << endl;
}