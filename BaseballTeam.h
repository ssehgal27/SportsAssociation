#pragma once
#include <iostream>
#include <string>
#include "Team.h"
#ifndef _BASEBALLTEAM_H_
#define _BASEBALLTEAM_H
using namespace std;
class BaseballTeam: public Team{
	std::string name;
	int noofwins;
	int noofloss;
	double winningpercentage;
public:
	BaseballTeam(std::string _name, int _wins, int _losses)
	{
		this->name = _name;
		this->noofwins = _wins;
		this->noofloss = _losses;
		this->winningpercentage = double(_wins)/double(_wins + _losses);

	}
	std::string GetName() const
	{
		return this->name;
	}
	Err_Status display() const
	{
		Err_Status retval = Err_Success;
		if (this->name == "" || this->noofwins == 0 || this->noofloss == 0 || this->winningpercentage==0)
		{
			retval = Err_Status::Err_Undefined;
			cout << "Failed to get information ";
		}
		else
		{
			cout.setf(std::ios::fixed);
			cout.precision(2);
			cout << this->name << "has" << this->noofwins << "wins," << this->noofloss << "losses for a winning percentage of  " << this->winningpercentage;
			cout << endl;
		}
		return retval;
	}
	bool operator==(const BaseballTeam& team1) const
	{
	     bool retval = true;
		if (this->winningpercentage != team1.winningpercentage)
		{
			retval = false;
		}
		return retval;
	}
};
#endif // _BASEBALLTEAM_H_