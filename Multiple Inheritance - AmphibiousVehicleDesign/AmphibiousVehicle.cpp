//AmphibiousVehicle.cpp - function definitions for  amphibious vehicle
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#include "AmphibiousVehicle.h"
#include <iostream>
using namespace std;
AmphibiousVehicle::AmphibiousVehicle(string _name, double Fuel_before) : Automobile(_name, 10.00, Fuel_before), Boat(_name,  Fuel_before)
{
	name = _name;
} 
Vehicle::Err_Status AmphibiousVehicle::Travel(double _dis)
{	try
	{
		Err_Status E1 = Err_Status::Err_Success;
		if (mode == VEHICLE_AUTOMOBILE)		{
			E1 = Automobile::Travel(_dis);
		}
		else {
			if (mode == VEHICLE_BOAT) {
				E1 = Boat::Travel(_dis);
			}
		}
		return E1;
	}
	catch (const char* message) {
		cout << message << "\n";
	}
}
Vehicle::Err_Status AmphibiousVehicle::AddFuel(double _amnt)
{
	Err_Status E1 = Err_Status::Err_Success;
	if (mode == VEHICLE_AUTOMOBILE){
		E1 = Automobile::AddFuel(_amnt);
	}
	else {
		if (mode == VEHICLE_BOAT) E1 = Boat::AddFuel(_amnt);
	}
	return E1;
}
string AmphibiousVehicle::GetName()
{
	return name;
}
double AmphibiousVehicle::GetCost()
{
	double tot = Automobile::GetCost() + Boat::GetCost();
	return tot;
}
double AmphibiousVehicle::GetFuel()
{
	double tot1 = Automobile::Getfuel() + Boat::GetFuel();
	return tot1;
}
void AmphibiousVehicle::SetMode(const unsigned short mode1)
{
	mode = mode1;
}
void AmphibiousVehicle::UnsetMode(const unsigned short mode2)
{
	mode = NONE;
}