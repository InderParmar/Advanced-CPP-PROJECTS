//HockeyTeam.cpp -  file for hockeyteam variables and functions definitons
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"HockeyTeam.h"
using namespace std;

HockeyTeam::HockeyTeam()
{
	Name = "";
	Wins = 0;
	Ties = 0;
	Losses = 0;
	Points = 0;
}

HockeyTeam::HockeyTeam(string _name, int _wins, int _ties, int _losses)
{
	Name = _name;
	Wins = _wins;
	Ties = _ties;
	Losses = _losses;
	Points = (2 * Wins) + Ties;
}

string HockeyTeam::GetName() const
{
	return Name;
}

Err_Status HockeyTeam::display() const
{
	Err_Status v{};
	if (Name == "")
	{
		v = Err_Status::Err_Undefined;
	}
	else if (Wins < 0 && Losses < 0 && Ties < 0)
	{
		v = Err_Status::Err_OutOfBounds;
	}
	else if (Points < 0)
	{
		v = Err_Status::Err_Calculation;
	}
	else
	{
		v = Err_Status::Err_Success;
		cout << Name << " has " << Wins << " wins, " << Ties << " Ties, and " << Losses << " losses for " << Points << " points." << endl;
	}
	return v;
}

bool HockeyTeam::operator==(const Team& vs) const
{
	const HockeyTeam* ht = dynamic_cast<const HockeyTeam*>(&vs);
	if (Points == ht->Points)
	{
		return true;
	}
	else { return false; }
}