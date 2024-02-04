//Customer.h - Class declaration for the customer
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail Id: iparmar1@myseneca.ca
//Date: 22 July 2022  
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <map>
#include <iostream>
using namespace std;
enum Err_Status {
	Err_Success,
	Err_InvalidData,
	Err_ResourceNotAvailable
};

class Customer {
	string Customer_Name;
	string Customer_Address;
	int Customer_Number;
	long long int Customer_Phone_Number; 

public:
	Customer();
	Customer(string _Customer_Name, string _Customer_Address, long long int _Customer_Phone_Number);
	string Get_Customer_Name(string Name1);
	string Get_Customer_Address(string Address1);
	int GetCustomer_Number();
	long long int Get_Customer_Phonenumber(long long int x);
	ostream& GetInfo();
	Err_Status Set_Cus_name();
	Err_Status Set_Cus_address();
	Err_Status Setphonenumber();
	Customer& Delete_Customers_Data();
};

#endif
