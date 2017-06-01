#include "Account.h"
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

	//Transaction deposit{ 200.00f, 300.00f };
	//deposit.setName("Deposited some money");
	//cout << deposit.toString() << endl << endl;

	//Transaction withdraw{ 100, 50 , "Removed some money"};
	//cout << withdraw.toString() << endl << endl;

	//Item mouse{ "Logitech G502", 59.99f };
	//unique_ptr<Item> mouse = make_unique<Item>("Logitech G502", 59.99f);
	//Transaction mouseBought(1000.00f, move(mouse), "Mouse bought");
	//cout << mouseBought.toString() << endl;

	//Account alex{ "Alex", 1000.00f };
	//Account otherAccount{ "Dank", 250.00f };
	//alex.addFunds(500.00f, "Deposit some money");
	//alex.deductFunds(250.00f, "Remove some funds for food");
	Item mouse{ "Logitech G502", 59.99f };
	//alex.purchaseItem(mouse, "Bought gaming mouse");
	//alex.purchaseItem(mouse, "Bought gaming mouse");
	//cout << alex.getHistoryOfDepositsAndWithdraws() << endl;
	//alex = move(otherAccount);

	Transaction deposit{ 100, 500, "Deposit" };
	cout << deposit.toString() << endl;
	deposit.setItemPurchased(mouse);
	deposit.setName("Logitech G502 Purchased");
	cout << deposit.toString() << endl;
}