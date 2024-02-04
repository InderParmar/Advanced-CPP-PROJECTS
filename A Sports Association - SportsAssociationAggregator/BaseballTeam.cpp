//BaseballTeam.cpp -  file for baseballteam variables and functions definitons

//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"BaseballTeam.h"
using namespace std;
BaseballTeam::BaseballTeam()
{
	Name = "";
	Wins = 0;
	Losses = 0;
	WinPercent = 0;
}

BaseballTeam::BaseballTeam(string _name, int _wins, int _losses)

{
	Name = _name;
	Wins = _wins;
	Losses = _losses;
	WinPercent = ((double)(Wins) / (double)(Wins + Losses));
}

string BaseballTeam::GetName() const
{
	return Name;
}

Err_Status BaseballTeam::display() const
{
	Err_Status v{};
	if (Name == "")
	{
		v = Err_Status::Err_Undefined;
	}
	else if (WinPercent < 0)
	{
		v = Err_Status::Err_Calculation;
	}
	else if (Wins < 0 && Losses < 0)
	{
		v = Err_Status::Err_OutOfBounds;
	}
	else
	{
		v = Err_Status::Err_Success;
		cout.setf(ios::fixed);
		cout.precision(6);
		cout << Name << " has " << Wins << " wins and " << Losses << " losses for a winnning percent of " << WinPercent << "." << endl;
	}
	return v;
}

bool BaseballTeam::operator==(const Team& vs) const
{
	const BaseballTeam* bt = dynamic_cast<const BaseballTeam*>(&vs);
	if (WinPercent == bt->WinPercent)
	{
		return true;
	}

	else { return false; }
}