//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail: iparmar1@myseneca.ca
#ifndef _COMPANYEMP_H_
#define _COMPANYEMP_H_
#include<iostream>
#include"CompanyCommon.h"
#include <iomanip>
using namespace std;
class CompanyEmployee
{
	StandardEmployee* STD1;
	int Num_Employees;
public:
	CompanyEmployee() {
		Num_Employees = 0;
		STD1 = nullptr;
	}

	bool AddPersonnel(int Num_of_persons) {
		bool retval = false;
		if (Num_Employees < MAX_SIZE) {
			StandardEmployee* STD2;
			STD2 = nullptr;
			STD2 = new StandardEmployee[Num_Employees + Num_of_persons];
			if (STD1 != nullptr)
			{
				for (int i = 0; i < Num_Employees; i++)
				{
					STD2[i].name = STD1[i].name;
					STD2[i].base_Salary = STD1[i].base_Salary;
					STD2[i].annual_performanceBonus = STD1[i].annual_performanceBonus;
					STD2[i].position = STD1[i].position;
					STD2[i].annual_profitSharing = STD1[i].annual_profitSharing;
					STD2[i].salary = STD1[i].salary;
				}
			}
			for (int i = 0; i < Num_of_persons; i++)
			{
				cout.setf(ios::fixed);
				cout << left << setw(20);
				cout << left << "Enter the employee's name: ";
				getline(cin, STD2[Num_Employees + i].name);
				cout << left << "Enter the employee's position: ";
				getline(cin, STD2[Num_Employees + i].position);
				cout << left << "Enter the employee's base salary: ";
				cin >> STD2[Num_Employees + i].base_Salary;
				cout << left << "Enter the employee's annual profit sharing amount:";
				cin >> STD2[Num_Employees + i].annual_profitSharing;
				cout << " Enter the employee's annual performance bonus: ";
				cin >> STD2[Num_Employees + i].annual_performanceBonus;
				cin.ignore();
				cout << endl;
			}
			Num_Employees += Num_of_persons;
			STD1 = nullptr;
			STD1 = new StandardEmployee[Num_Employees];

			for (int i = 0; i < Num_Employees; i++)
			{
				STD1[i].name = STD2[i].name;
				STD1[i].base_Salary = STD2[i].base_Salary;
				STD1[i].annual_performanceBonus = STD2[i].annual_performanceBonus;
				STD1[i].position = STD2[i].position;
				STD1[i].annual_profitSharing = STD2[i].annual_profitSharing;
				STD1[i].salary = STD2[i].salary;
			}
			delete[] STD2;
			retval = true;
		}
		else
		{
			cout << "Error: There is no memory left";
			retval = false;
		}
		return retval;
	}
	bool FindPersonnel(std::string Name_of_persons, StandardEmployee& STD3) {
		bool retval = false;
		for (int i = 0; i < Num_Employees; i++)
		{
			if (STD1[i].name == Name_of_persons)
			{
				STD3.name = STD1[i].name;
				STD3.base_Salary = STD1[i].base_Salary;
				STD3.annual_performanceBonus = STD1[i].annual_performanceBonus;
				STD3.position = STD1[i].position;
				STD3.annual_profitSharing = STD1[i].annual_profitSharing;
				STD3.salary = STD1[i].salary;
				retval = true;
			}
		}
		return retval;
	}
	double CalculateSalary(std::string Name_of_persons) {
		bool retval = false;
		for (int i = 0; i < Num_Employees; i++)
		{
			if (STD1[i].name == Name_of_persons)
			{
				retval = true;
				STD1[i].salary = STD1[i].base_Salary + STD1[i].annual_performanceBonus + STD1[i].annual_profitSharing;
				return STD1[i].salary;
			}

		}
		if (retval = false)
		{
			return  0.00;
		}

	}
	~CompanyEmployee() {};
};
#endif//_COMPANYEMP_H_