#include<iostream>
#include "BaseballTeam.h"
#include "HockeyTeam.h"
constexpr int MAX_TEAMS = 4;
using namespace std;
class SportsAssociation
{
	std::string nameofassociation;
	const Team* team[MAX_TEAMS];
	int noofteams;
public:
	SportsAssociation()
	{
		this->nameofassociation = "";
		noofteams = 0;
	}
	SportsAssociation(std::string _nameofassociation)
	{
		this->nameofassociation = _nameofassociation;
		noofteams = 0;
	}
	SportsAssociation& operator+=(const Team& team1)
	{
		bool val = true;
			if (noofteams>MAX_TEAMS)
			{
				val = false;
				cout << "Number of teams have been exceeded!!!";
				cout << std::endl;
			}
			for (int i = 0; i < MAX_TEAMS; ++i)
			{
				if(*team[i] == team1)
				{
					val = false;
					cout << team[i]->GetName() << "is similar to" << team1.GetName();
				}
				if (val == true)
				{
					team[noofteams] = &team1;
					++noofteams;
				}
			}
			return *this;
		
	}

	void display()
	{   
		cout.setf(std::ios::fixed);
		cout.precision(2);
		cout << std::endl;
		cout << nameofassociation << "has the following teams:\n";
		for (int i = 0; i < noofteams; ++i)
		{  
			Err_Status ret = team[i]->display();
		}
	}
};
#ifndef _SPORTSASSOCIATION_H_
#define _SPORTSASSOCIATION_H_

#endif // _SPORTSASSOCIATION_H_
