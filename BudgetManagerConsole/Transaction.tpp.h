#pragma once
#include "Transaction.h"

template <typename Name>
void Transaction::setName(Name&& newName)
{
	name = std::forward<Name>(newName);
}

template <typename NewItem>
void Transaction::setItemPurchased(NewItem&& newItem)
{
	// Create unique_ptr<Item> of item
	auto purchasedItem = std::make_unique<Item>(std::forward<NewItem>(newItem));
	if (newItem.getCost() < amountBefore)
	{
		switch (typeOfTransaction)
		{
		case Change::itemPurchased:
			// Switch previous item with new purchased item
			itemPurchased = std::move(purchasedItem);
			// Update amountAfter with cost of new item
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			break;
		case Change::deposit:
			// Instantiate itemPurchasd with item
			itemPurchased = std::move(purchasedItem);
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			typeOfTransaction = Change::itemPurchased;
			break;
		case Change::withdraw:
			itemPurchased = std::move(purchasedItem);
			changeInBalance = itemPurchased->getCost();
			amountAfter = amountBefore - changeInBalance;
			typeOfTransaction = Change::itemPurchased;
			break;
		}
	}
	else
	{
		return;
	}
}