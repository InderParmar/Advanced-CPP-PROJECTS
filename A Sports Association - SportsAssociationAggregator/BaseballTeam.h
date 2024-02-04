//BaseballTeam.h- Header file for hockey team variable and constructor declarations
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"Team.h"
#ifndef _BASEBALLTEAM_H_
#define _BASEBALLTEAM_H_
#include <iostream>
using namespace std;
class BaseballTeam : public Team
{
	string Name;
	int Wins;
	int Losses;
	double WinPercent;
public:
	BaseballTeam();
	BaseballTeam(string _name, int _wins, int _losses);
	string GetName() const;
	Err_Status display() const;
	bool operator==(const Team& vs) const;
};

#endif