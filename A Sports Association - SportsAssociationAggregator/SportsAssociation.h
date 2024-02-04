//SportsAssociation.h - Header file for teams of sports association variables and functions declarations
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"Team.h"
#include "BaseballTeam.h"
#include "HockeyTeam.h"
using namespace std;
constexpr auto MAX = 4;
#ifndef _SPORTSASSOCIATION_H_
#define _SPORTSASSOCIATION_H_
class SportsAssociation
{
private:
	char* assoc = nullptr;
	int Team_num = 0;
	const Team* T[MAX];
public:
	SportsAssociation(const char* _assoc);
	bool operator+=(const Team&);
	ostream& display();
};
#endif