//Automobile.h - header file for automobile 
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_
#include "Vehicle.h"
using namespace std;
class Automobile : public Vehicle //inheriting from base class vehicle
{
	string name;
	double efficiency = 10.00;
	double fuelTank;
	double Cost;
	const double CostPr_L = 1.30;
	const double tankCapacity = 50.00;
public:
	Automobile();
	Automobile(string _name, double _efficiency, double _fuelTank);
	Err_Status Travel(double _distance);
	Err_Status AddFuel(double _amnt);
	double Getfuel();
	double GetCost();
	virtual ~Automobile() = default;
};
#endif