//Vehicle.h - header file   for a vehicle
// Name       : Inderpreet Singh Parmar
// Student Id : 164132219
// Mail Id    : iparmar1@myseneca.ca
#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>
class Vehicle {
public:
	enum class Err_Status {
		Err_Success,
		Err_NoFuel, 
		Err_Morefuel,
		Err_Incorrect_Mode
	};
	virtual Err_Status Travel(double _dis) = 0; 
	virtual Err_Status AddFuel(double _amnt) = 0;  
	virtual double GetFuel() = 0;                   
	virtual double GetCost() = 0;	
	virtual ~Vehicle() = default;
};
#endif