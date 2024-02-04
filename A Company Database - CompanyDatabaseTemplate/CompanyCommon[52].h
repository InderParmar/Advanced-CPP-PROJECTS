//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Mail: iparmar1@myseneca.ca
#ifndef _COMPANYBASE_H_
#define _COMPANYBASE_H_
const int MAX_SIZE = 1000;
#include <iostream>
#include <string>
typedef struct StandardEmployee {
	std::string name;
	std::string position;
	double base_Salary;
	double annual_profitSharing;
	double annual_performanceBonus;
	double salary;
};
typedef struct ExecutiveEmployee {
	std::string name;
	std::string position;
	double base_Salary;
	double annual_stockOptionDividend;
	double annual_perquisites;
	double salary;
};
template <typename T, typename structure >
bool FindPersonnel(T& element, std::string Name, structure& STD) {
	bool retval = false;
	retval = element.FindPersonnel(Name, STD);
	return retval;
}
template <typename T >
bool AddPersonnel(T& element, int Num_of_persons) {
	bool retval = false;
	retval = element.AddPersonnel(Num_of_persons);
	return retval;
}
template <typename T >
double CalculateSalary(T& element, std::string Name_of_persons) {
	double Salary = 0.00;
	Salary = element.CalculateSalary(Name_of_persons);
	return Salary;
}
#endif//_COMPANYBASE_H_