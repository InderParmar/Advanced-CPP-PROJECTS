// InvestmentAccount.cpp - function definitions for an investment account

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

InvestmentAccount::InvestmentAccount()
{
	cash = 0.00;
	stocks = 0.00;
	name = "";
}

InvestmentAccount::InvestmentAccount(std::string name1, double cash1)
{
	cash = cash1;
	stocks = 0.00;
	name = name1;
}

bool InvestmentAccount::PurchaseStocks(double amount)
{
	bool success = true;
	if (this->cash < amount)
	{
		success = false;
	}
	else
	{
		this->cash -= amount;
		stocks += amount;
	}

	return success;
}

bool InvestmentAccount::SellStocks(double amount)
{
	bool success = true;
	if (stocks < amount)
	{
		success = false;
	}
	else
	{
		this->cash += amount;
		stocks -= amount;
	}
	return success;
}

std::string InvestmentAccount::GetName() const
{
	return this->name;
}

double InvestmentAccount::GetValue() const
{
	return this->cash + this->stocks;
}

double InvestmentAccount::GetStocks() const
{
	return this->stocks;
}

double InvestmentAccount::GetCash() const
{
	return this->cash;
}

// Implement the overload of the += operator
// This should add cash to the investment account
// If the amount to be added is negative, print out the error message "Invalid transaction"
// Do not forget the function prototype in the header file InvestmentAccount.h

InvestmentAccount &InvestmentAccount::operator+=(double cash1)
{
	if (cash1 < 0)
	{
		cout << "Invalid transaction" << endl;
	}
	else
	{
		this->cash += cash1;
	}

	return *this;
}
// Implement the overload of the -= operator
// This should withdraw cash from the investment account
// If the amount to be withdrawn is negative, print out the error message "Invalid transaction"
// If there isn't enough cash in the account, print out the error message "Not enough funds"
// Do not forget the function prototype in the header file InvestmentAccount.h

InvestmentAccount &InvestmentAccount::operator-=(double cash1)
{
	double ThisCash = this->cash;
	if (cash1 < 0)
	{
		cout << "Invalid transaction" << endl;
	}
	else
	{
		ThisCash -= cash1;
	}
	if(ThisCash < 0)
	{
		cout<<"Not enough funds in the account for "<<this->name<<"."<<endl;
		return *this;
	}
	this->cash = ThisCash;
	return *this;
}

// Implement the overloading of the == operator
// where true is returned if the names of the investment accounts are the same, false otherwise
// Do not forget the function prototype in the header file BankManager.h

bool InvestmentAccount::operator==(const InvestmentAccount &check) const
{
	bool retVal = false;
	if (this->name == check.name)
		retVal = true;
	return retVal;
}

InvestmentAccount::~InvestmentAccount()
{ // wipe out all information
	cash = 0.00;
	stocks = 0.00;
	name = "";
}