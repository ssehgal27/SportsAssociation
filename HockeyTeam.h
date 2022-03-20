#pragma once
#include <iostream>
#include <string>
#include "Team.h"
#ifndef _HOCKEYTEAM_H_
#define _HOCKEYTEAM_H
using namespace std;
class HockeyTeam : public Team
{
	std::string name;
	int noofwins;
	int noofloss;
	int noofties;
	int points;
public:
	HockeyTeam(std::string _name, int _wins, int _ties,int _loss)
	{
		this->name = _name;
		this->noofwins = _wins;
		this->noofloss = _loss;
		this->noofties = _ties;
		this->points = 2 * (_wins + _ties);
	}
	std::string GetName() const
	{
		return this->name;
	}
	Err_Status display() const
	{
		Err_Status retval = Err_Success;
		if (this->name == "" || this->noofloss == 0 || this->noofties == 0 || this->noofwins == 0 || this->points == 0)
		{
			retval = Err_Status::Err_Undefined;
		}
		else
		{
			cout.setf(std::ios::fixed);
			cout.precision(2);
			cout << this->name << "has" << this->noofwins << "wins," << this->noofties << "ties, and" << this->noofloss << "losses for " << this->points;
			cout << endl;
		}
		return retval;
	}
	bool operator==(const HockeyTeam& team1) const
	{
		bool retval = true;
		if (this->points != team1.points)
		{
			retval = false;
		}
		return retval;
	}
};

#endif // _HOCKEYTEAM_H_