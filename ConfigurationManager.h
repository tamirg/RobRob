/*
 * ConfigurationManager.h
 *
 *  Created on: Jun 12, 2015
 *      Author: colman
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <wordexp.h>

using namespace std;

class ConfigurationManager {
private:
	string _mapPath;
	int _startLocationX;
	int _startLocationY;
	double _startLocationYaw;
	int _goalX;
	int _goalY;
	double _robotWidth;
	double _robotLength;
	double _mapResolutionCM;
	double _gridResolutionCM;
	void RemoveParameterName(string* parameter);
	int GetNextInt(string* stringToParse);
	double GetNextDouble(string* stringToParse);

public:
	ConfigurationManager();
	virtual ~ConfigurationManager();
	string GetMapPath();
	int GetStartLocationX();
	int GetStartLocationY();
	double GetStartLocationYaw();
	int GetGoalX();
	int GetGoalY();
	double GetRobotWidth();
	double GetRobotLength();
	double GetMapResolutionCM();
	double GetGridResolutionCM();
};

#endif /* CONFIGURATIONMANAGER_H_ */
