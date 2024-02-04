//Automobile.cpp - function definitions for  automobile
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#include "Automobile.h"
#include <iomanip>
using namespace std;
Automobile::Automobile() {
	name = "";
	fuelTank = 0;
	Cost = 0;
}
Automobile::Automobile(string _name, double _efficiency, double _fuelTank) {
	name = _name;
	efficiency = _efficiency;
	if (_fuelTank > tankCapacity){
		
		fuelTank = tankCapacity;
		Cost = tankCapacity * CostPr_L;
	}
	else{
		fuelTank = _fuelTank;
		Cost = fuelTank * CostPr_L;
	}
	cout << name << " automobile has added " << fuelTank << "L at a cost of $" << Cost << "." << "\n"<<"\n";
}
Vehicle::Err_Status Automobile::Travel(double _dis) {
	double used = 0;
	used = _dis / efficiency;
	if (used > fuelTank){
		throw "Automobile out of fuel";
		return Err_Status::Err_NoFuel;
	}
	else{
		fuelTank -= used;
		cout << fixed;
		cout << setprecision(2);
		cout << name << " automobile has " << fuelTank << "L of fuel left. It has travelled " << _dis << "km at a cost of $" << (used * CostPr_L) << setprecision(2) << "." << "\n";
		return Err_Status::Err_Success;
	}
}
Vehicle::Err_Status Automobile::AddFuel(double _amnt) {
	if ((fuelTank + _amnt) > tankCapacity)	{
		double Actual_Fuel = (tankCapacity - fuelTank);
		cout << name << " automobile has encountered a fuel overflow. The amount added is actually " << Actual_Fuel << setprecision(2) << "L at a cost of $" << setprecision(2) << (Actual_Fuel * CostPr_L) << "." << "\n";
		fuelTank = tankCapacity;
		Cost += (Actual_Fuel * CostPr_L);
		return Err_Status::Err_Morefuel;

	}
	else{
		fuelTank += _amnt;
		cout << setprecision(2) << _amnt << "L has been added to " << name << " automobile. The cost was $" << setprecision(2) << (_amnt * CostPr_L);
		Cost += (_amnt * CostPr_L);
		return Err_Status::Err_Success;
	}
}
double Automobile::Getfuel()
{
	return fuelTank;
}
double Automobile::GetCost()
{
	return Cost;
}