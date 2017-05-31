#include "Account.h"
#include "Transaction.h"
#include <iostream>

using namespace std;

int main()
{

	//Account a{};
	//a.setName("Jean Valjean");
	//a.setBalance(100);
	//Item mouse{ "Logitech G502", 59.99f };
	//unique_ptr<Item> book = make_unique<Item>("Zero to One", 25.99f);
	//a.purchaseItem(mouse);
	//cout << a.getBalance() << endl;
	//a.purchaseItem(move(book));
	//cout << a.getBalance() << endl;

	Transaction deposit{ 200.00f, 300.00f };
	deposit.setName("Deposited some money");
	cout << deposit.toString() << endl << endl;

	Transaction withdraw{ 100, 50 , "Removed some money"};
	cout << withdraw.toString() << endl << endl;

	//Item mouse{ "Logitech G502", 59.99f };
	unique_ptr<Item> mouse = make_unique<Item>("Logitech G502", 59.99f);
	Transaction mouseBought(1000.00f, move(mouse), "Mouse bought");
	cout << mouseBought.toString() << endl;
}