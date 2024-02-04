//Boat.h - header file for declarations of functions for a boat
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#ifndef _BOAT_H_
#define _BOAT_H_
#include "Vehicle.h"
using namespace std;
class Boat : public Vehicle {
	string name;
	double fuelTank;
	double Cost;
	const double efficiency = 20.00;
	const double boat_Speed = 20.0;
	const double CostPr_L = 1.60;
	const double tankCapacity = 150.0;
public:
	Boat();
	Boat(string _name, double);
	Err_Status Travel(double _dis);
	Err_Status AddFuel(double _amnt);
	double GetCost();
	double GetFuel();
	virtual ~Boat() = default;
};

#endif