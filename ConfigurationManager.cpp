/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: colman
 */

#include "ConfigurationManager.h"

ConfigurationManager::ConfigurationManager()
{
	string strParameter;
	ifstream parametersFile ("parameters.txt");

	// Check if file is open
	if (parametersFile.is_open())
	{
		// Get map path
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
	   	wordexp_t exp_result;
		wordexp(strParameter.c_str(), &exp_result, 0);
		this->_mapPath = exp_result.we_wordv[0];
		wordfree(&exp_result);


		// Get robot's start location X, Y, Yaw
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
		this->_startLocationX = this->GetNextInt(&strParameter);
		this->_startLocationY = this->GetNextInt(&strParameter);
		this->_startLocationYaw = this->GetNextDouble(&strParameter);

		// Get robot's goal
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
		this->_goalX = this->GetNextInt(&strParameter);
		this->_goalY = this->GetNextInt(&strParameter);

		// Get robot's size
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
		this->_robotWidth = this->GetNextDouble(&strParameter);
		this->_robotLength = this->GetNextDouble(&strParameter);

		// Get map resolution in CM
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
		this->_mapResolutionCM = this->GetNextDouble(&strParameter);

		// Get grid resolution in CM
		getline (parametersFile,strParameter);
		this->RemoveParameterName(&strParameter);
		this->_gridResolutionCM = this->GetNextDouble(&strParameter);

		// Close the parameter file
		parametersFile.close();
	}
	else
		cout << "Unable to open file";
}

// Remove the parameter name from the string, returns only the value
void ConfigurationManager::RemoveParameterName(string* parameter)
{
	int spacePosition;

	spacePosition = parameter->find(" ");
	parameter->erase(0, spacePosition + 1);
}

// Get the next number in the string, and return it as int.
// Remove the returned number from the string
int ConfigurationManager::GetNextInt(string* stringToParse)
{
	int spacePosition;
	string nextInt;
	int intToReturn;

	spacePosition = stringToParse->find(" ");

	// If space was found
	if (spacePosition != string::npos)
	{
		nextInt = stringToParse->substr(0, spacePosition);
		stringToParse->erase(0, spacePosition + 1);
	}
	else
		nextInt = *stringToParse;

	istringstream convert(nextInt);
	convert >> intToReturn;

	return (intToReturn);
}

// Get the next number in the string, and return it as double.
// Remove the returned number from the string
double ConfigurationManager::GetNextDouble(string* stringToParse)
{
	int spacePosition;
	string nextDouble;
	double doubleToReturn;

	spacePosition = stringToParse->find(" ");

	// If space was found
	if (spacePosition != string::npos)
	{
		nextDouble = stringToParse->substr(0, spacePosition);
		stringToParse->erase(0, spacePosition + 1);
	}
	else
		nextDouble = *stringToParse;

	stringstream convert(nextDouble);
	convert >> doubleToReturn;

	return (doubleToReturn);
}

string ConfigurationManager::GetMapPath()
{
	return (this->_mapPath);
}

int ConfigurationManager::GetStartLocationX()
{
	return (this->_startLocationX);
}

int ConfigurationManager::GetStartLocationY()
{
	return (this->_startLocationY);
}

double ConfigurationManager::GetStartLocationYaw()
{
	return (this->_startLocationYaw);
}

int ConfigurationManager::GetGoalX()
{
	return (this->_goalX);
}

int ConfigurationManager::GetGoalY()
{
	return (this->_goalY);
}

double ConfigurationManager::GetRobotWidth()
{
	return (this->_robotWidth);
}

double ConfigurationManager::GetRobotLength()
{
	return (this->_robotLength);
}

double ConfigurationManager::GetMapResolutionCM()
{
	return (this->_mapResolutionCM);
}

double ConfigurationManager::GetGridResolutionCM()
{
	return (this->_gridResolutionCM);
}

ConfigurationManager::~ConfigurationManager()
{
}

