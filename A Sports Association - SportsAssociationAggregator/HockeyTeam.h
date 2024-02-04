//HockeyTeam.h- Header file for hockey team variable and constructor declarations
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"Team.h"
#ifndef _HOCKEYTEAM_H_
#define _HOCKEYTEAM_H_
#include <iostream>
using namespace std;
class HockeyTeam : public Team
{
	string Name;
	int Wins;
	int Ties;
	int Losses;
	int Points;
public:
	HockeyTeam();
	HockeyTeam(string _name, int _wins, int _ties, int _losses);
	Err_Status display() const;
	string GetName() const;
	bool operator==(const Team& vs) const;
};
#endif

