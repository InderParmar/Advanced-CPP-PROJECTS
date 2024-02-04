//Customer.cpp - Function definitions for the customer
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail Id: iparmar1@myseneca.ca
//Date: 22 July 2022 

#include <string>
#include "Customer.h"

using namespace std;

static int _Customer_Number = 0;

Customer::Customer()
{
	Customer_Name = "";
	Customer_Address = "";
	 Customer_Phone_Number = 0;
	_Customer_Number++;
}

Customer::Customer(string _Customer_Name, string _Customer_Address, long long int _Customer_Phone_Number)
{
	Customer_Name = _Customer_Name;
	Customer_Address = _Customer_Address;
	Customer_Number = _Customer_Number;
	Customer_Phone_Number = _Customer_Phone_Number;
}
string Customer::Get_Customer_Name(string Name1)
{
	Customer_Name = Name1;
	return Customer_Name;
}

string Customer::Get_Customer_Address(string Address1)
{
	Customer_Address = Address1;
	return Customer_Address;
}

long long int Customer::Get_Customer_Phonenumber(long long int x)
{
	Customer_Phone_Number = x;
	return Customer_Phone_Number;
}

int Customer::GetCustomer_Number()
{
	return Customer_Number;
}

ostream& Customer::GetInfo()
{
	cout << "Name: " << Customer_Name << endl;
	cout << "Address: " << Customer_Address << endl;
	cout << "Customer number: " << Customer_Number << endl;
	cout << "Phone number: " << Customer_Phone_Number << endl<<endl<<endl;
	return cout;
}
Err_Status Customer::Set_Cus_name()
{
	Err_Status flag = Err_Status::Err_Success;
	if (Customer_Name == "")
	{
		flag = Err_Status::Err_InvalidData;
	}
	else if (Customer_Name.size() <= 0)
	{
		flag = Err_Status::Err_ResourceNotAvailable;
	}
	return flag;
}

Err_Status Customer::Set_Cus_address()
{
	Err_Status flag = Err_Status::Err_Success;
	if (Customer_Address == "")
	{
		flag = Err_Status::Err_InvalidData;
	}
	else if (Customer_Address.size() <= 0)
	{
		flag = Err_Status::Err_ResourceNotAvailable;
	}
	return flag;
}

Err_Status Customer::Setphonenumber()
{
	Err_Status flag = Err_Status::Err_Success;
	if (Customer_Phone_Number <= 0 || Customer_Phone_Number >= 9999999999)
	{
		flag = Err_Status::Err_InvalidData;
	}
	return flag;
}

Customer& Customer::Delete_Customers_Data()
{
	Customer_Name = "";
	Customer_Address = "";
	Customer_Phone_Number = 0;
	Customer_Number = 0;
	return *this;
}