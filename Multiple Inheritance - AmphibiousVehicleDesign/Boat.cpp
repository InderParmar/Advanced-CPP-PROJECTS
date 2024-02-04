//Boat.cpp - cpp file for boat and definitions
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#include "Boat.h"
#include<iomanip>
Boat::Boat()
{
	name = "";
	fuelTank = 0.00;
	Cost = 0.00;
}

Boat::Boat(string _name,  double _fuelTank) {
	name = _name;
	if (_fuelTank > tankCapacity){
		fuelTank = tankCapacity;
		Cost = CostPr_L * tankCapacity ;
	}
	else{
		fuelTank = _fuelTank;
		Cost = CostPr_L * fuelTank  ;
	}
	cout << "\n";
	cout << name << " boat has added " << fuelTank << "L at a cost of $" << setprecision(3) << Cost << "." << "\n";
	cout << "\n";
}
Vehicle::Err_Status Boat::Travel(double _dis)
{
	double time, fuel_used = 0.0;
	time = _dis / boat_Speed;
	fuel_used = time * efficiency;
	double ft = fuelTank;
	if (fuel_used > ft)	{
		throw "Boat out of fuel";
		return Err_Status::Err_NoFuel;
	}
	else{
		fuelTank = fuelTank - fuel_used;
		cout << fixed;
		cout << setprecision(2);
		cout << name << " boat has " << fuelTank << "L of fuel left. It has travelled " << _dis << "km at a cost of $" << (fuel_used * CostPr_L) << "." << "\n";
		return Err_Status::Err_Success;
	}
}
Vehicle::Err_Status Boat::AddFuel(double _amnt) {
	double tot = _amnt + fuelTank;
	if (tot > tankCapacity){
		double Fuel = (tankCapacity - fuelTank);
		fuelTank = tankCapacity;
		cout << name << " boat has encountered a fuel overflow. The amount added is actually " << Fuel << setprecision(2) << "L at a cost of $" << setprecision(2) << (Fuel * CostPr_L) << "\n";
		Cost = Cost +  (Fuel * CostPr_L);
		return Err_Status::Err_Morefuel;
	}
	else{
		fuelTank = fuelTank + _amnt;
		cout << setprecision(3) << _amnt << "L has been added to " << name << " boat. The cost was $" << setprecision(2) << (_amnt * CostPr_L);
		Cost = Cost + (_amnt * CostPr_L);
	}
}
double Boat::GetFuel()
{
	return fuelTank;
}
double Boat::GetCost()
{
	return Cost;
}