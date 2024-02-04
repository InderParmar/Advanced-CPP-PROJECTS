//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail: iparmar1@myseneca.ca
#include<iostream>
#include"CompanyCommon.h"
#include <iomanip>
class CompanyExecutive
{
	ExecutiveEmployee* STD1;
	int Num_Emp;
public:
	CompanyExecutive() {
		Num_Emp = 0;
		STD1 = nullptr;
	}
	bool AddPersonnel(int Num_of_persons) {
		bool retval = false;

		if (Num_Emp < MAX_SIZE) {
			ExecutiveEmployee* STD2;
			STD2 = nullptr;
			STD2 = new ExecutiveEmployee[Num_Emp + Num_of_persons];
			if (STD1 != nullptr)
			{
				for (int i = 0; i < Num_Emp; i++)
				{
					STD2[i].name = STD1[i].name;
					STD2[i].base_Salary = STD1[i].base_Salary;
					STD2[i].annual_stockOptionDividend = STD1[i].annual_stockOptionDividend;
					STD2[i].position = STD1[i].position;
					STD2[i].annual_perquisites = STD1[i].annual_perquisites;
					STD2[i].salary = STD1[i].salary;
				}
			}

			for (int i = 0; i < Num_of_persons; i++)
			{
				cout.setf(ios::left);
				cout << left << setw(13);
				cout << left << " Enter the executive's name: ";
				getline(cin, STD2[Num_Emp + i].name);
				cout << left << " Enter the executive's position: ";
				getline(cin, STD2[Num_Emp + i].position);
				cout << left << "Enter the executive's base salary: ";
				cin >> STD2[Num_Emp + i].base_Salary;
				cout << left << "Enter the executive's annual stock option dividend :";
				cin >> STD2[Num_Emp + i].annual_stockOptionDividend;
				cout << left << setw(13) << " Enter the executive's annual perquisites: ";
				cin >> STD2[Num_Emp + i].annual_perquisites;
				cin.ignore();
				cout << endl;
			}
			Num_Emp += Num_of_persons;
			STD1 = nullptr;
			STD1 = new ExecutiveEmployee[Num_Emp];
			for (int i = 0; i < Num_Emp; i++)
			{
				STD1[i].name = STD2[i].name;
				STD1[i].base_Salary = STD2[i].base_Salary;
				STD1[i].annual_stockOptionDividend = STD2[i].annual_stockOptionDividend;
				STD1[i].position = STD2[i].position;
				STD1[i].annual_perquisites = STD2[i].annual_perquisites;
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

	double CalculateSalary(std::string Name_of_persons) {
		bool retval = false;
		for (int i = 0; i < Num_Emp; i++)
		{
			if (STD1[i].name == Name_of_persons)
			{
				retval = true;
				STD1[i].salary = (STD1[i].base_Salary + STD1[i].annual_stockOptionDividend + STD1[i].annual_perquisites);
				return STD1[i].salary;
			}
		}
		if (retval = false)
		{
			return  0.00;
		}

	}
	bool FindPersonnel(std::string Name_of_persons, ExecutiveEmployee& STD3) {
		bool retval = false;
		for (int i = 0; i < Num_Emp; i++)
		{
			if (STD1[i].name == Name_of_persons)
			{
				STD3.name = STD1[i].name;
				STD3.base_Salary = STD1[i].base_Salary;
				STD3.annual_stockOptionDividend = STD1[i].annual_stockOptionDividend;
				STD3.position = STD1[i].position;
				STD3.annual_perquisites = STD1[i].annual_perquisites;
				STD3.salary = STD1[i].salary;
				retval = true;
			}
		}
		return retval;
	}
	~CompanyExecutive() {};
};
