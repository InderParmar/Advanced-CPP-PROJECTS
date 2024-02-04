//SportsAssociation.cpp - file for checking the similarities and dispaying the output regarding sports team
//Name: Inderpreet Singh Parmar
//Student Id: 164132219
//Seneca mail ID : iparmar1@myseneca.ca
#include"SportsAssociation.h"
using namespace std;
SportsAssociation::SportsAssociation(const char* _assoc)
{
	assoc = new char[100];
	for (int i = 0; i < 100; i++)
	{
		assoc[i] = _assoc[i];
	}
}

bool SportsAssociation::operator+=(const Team& team)
{
	if (Team_num < MAX)
	{
		T[Team_num] = &team;
		Team_num++;
	}
	for (int i = 1; i < Team_num; i++)
	{

		for (int j = 0; j < i; j++)
		{

			if (typeid(*T[i]) == typeid(*T[j]))
			{
				bool retVal = T[i]->operator==(*T[j]);
				if (retVal == true)
				{
					cout << T[j]->GetName() << " is similar to " << T[i]->GetName() << "." << "\n\n\n";
				}
			}
		}
	}
	if (Team_num > 4)
	{
		cout << "limit exceeded " << endl;
	}
	return true;
}

ostream& SportsAssociation::display()
{
	cout << "The " << assoc << " has the following teams: " << endl;
	cout.setf(ios::fixed);
	cout.precision(6);
	for (int i = 0; i < MAX; i++)
	{
		T[i]->display();
	}
	return cout;
}