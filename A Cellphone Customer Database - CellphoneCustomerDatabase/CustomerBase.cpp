//CustomerBase.cpp - The main function for a map of customers
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail Id: iparmar1@myseneca.ca
//Date: 22 July 2022 
#include <map>
#include "Customer.h"

using namespace std;

int main() {
	map<long long int, Customer> customerMap;
	char firstname[] = "Aaaa";
	char lastname[] = "Bbbb";
	int streetNo = 0;
	char streetname[] = "Cccc";
	long long int phoneNo = 1111111110;

	//Build a database of 160,000 entries
	for (int i = 0; i < 20; ++i) {
		++firstname[0];
		++lastname[0];
		++streetname[0];
		firstname[1] = 'a';
		lastname[1] = 'b';
		streetname[1] = 'c';
		for (int j = 0; j < 20; ++j) {
			++firstname[1];
			++lastname[1];
			++streetname[1];
			firstname[2] = 'a';
			lastname[2] = 'b';
			streetname[2] = 'c';
			for (int k = 0; k < 20; ++k) {
				++firstname[2];
				++lastname[2];
				++streetname[2];
				++streetNo;
				firstname[3] = 'a';
				lastname[3] = 'b';
				streetname[3] = 'c';
				for (int l = 0; l < 20; ++l) {
					++firstname[3];
					++lastname[3];
					++streetname[3];
					++phoneNo;
					char name[16];
					char addr[32];
					sprintf_s(name, 16, "%s %s", firstname, lastname);
					sprintf_s(addr, 32, "%d %s Drive", streetNo, streetname);
					customerMap.insert(make_pair(phoneNo, Customer()));
					Customer customerMap1(name, addr, phoneNo);
					customerMap[phoneNo] = customerMap1;
					
				}

			}
		}
	}

	map<long long int, Customer>::iterator it;
	it = customerMap.find(1111112222);
	if (it != customerMap.end())
	{
		if (it->second.Set_Cus_name() == Err_Success && it->second.Set_Cus_address() == Err_Success && it->second.Setphonenumber() == Err_Success)
			it->second.GetInfo();
		else
			cout << "Invalid data." << endl;
	}
	else
	{
		cout << "cannot find the customer." << "\n\n";
	}
	it = customerMap.find(1111112222);
	if (it != customerMap.end())
	{
		if (it->second.Set_Cus_name() == Err_Success && it->second.Set_Cus_address() == Err_Success && it->second.Setphonenumber() == Err_Success)
		{
			it->second.Get_Customer_Name("Darryl Smith");
			it->second.Get_Customer_Address("1 Bloor Street");
			it->second.Get_Customer_Phonenumber(9051112222);
			it->second.GetInfo();
		}
		else
		{
			cout << "Invalid data." << endl;
		}
	}
	else
	{
		cout << "cannot find the customer." << "\n\n";
	}
	customerMap.erase(9051112222);
	it = customerMap.find(9051112222);
	if (it != customerMap.end())
	{
		if (it->second.Set_Cus_name() == Err_Success && it->second.Set_Cus_address() == Err_Success && it->second.Setphonenumber() == Err_Success)
			it->second.GetInfo();
		else
			cout << "Invalid data." << endl;
	}
	else
	{
		cout << "Cannot find the customer." << "\n\n";
	}
	it = customerMap.begin();
	do{
		it->second.Delete_Customers_Data();
		it++;
		}while (it != customerMap.end());

	it = customerMap.find(1111112222);
	if (it != customerMap.end())
		it->second.GetInfo();
	else
		cout << "Cannot find the customer." << "\n\n";

	return 0;
}