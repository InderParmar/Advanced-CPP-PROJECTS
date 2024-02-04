//AmphibiousVehicle.h - header file for AmphibiousVehicle
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#ifndef _AMPHIBIOUSVEHICLE_H_
#define _AMPHIBIOUSVEHICLE_H_
#include <iostream>
#include "Boat.h"
#include "Automobile.h"
class AmphibiousVehicle :public Boat, public Automobile {
	string name;
	unsigned short mode = 0x00;
public:
	static const unsigned short VEHICLE_AUTOMOBILE = 0x01;
	static const unsigned short VEHICLE_BOAT = 0x02;
	static	const unsigned short NONE = 0x03;
	AmphibiousVehicle(string _name, double Fuel_before);
	Err_Status Travel(double _dis);
	Err_Status AddFuel(double _amnt);
	double GetFuel();
    string GetName();
	double GetCost();
	void SetMode(const unsigned short mode1);
	void UnsetMode(const unsigned short mode2);
};
#endif