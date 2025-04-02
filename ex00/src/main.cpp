/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:04:30 by phwang            #+#    #+#             */
/*   Updated: 2025/04/02 19:44:21 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.hpp"

using std::cout;
using std::endl;

static int err_msg(const std::string msg, char *arg)
{
	cout << RED << msg << RESET;
	cout << arg << endl;
	return 1;
}

static bool checkArg(int argc, char **argv)
{
	if(argc == 1)
	{
		cout << BLUE << "Please enter an argument" << RESET << endl;
		return false;
	}
	else if(argc > 2)
	{
		cout << BLUE << "Too many arguments" << RESET << endl;
		return false;
	}
	std::string arg = argv[1]; // donc la cest un implicit cast
	if(arg.empty())
	{
		cout << RED << "Argument can't be empty" << RESET << endl;
		return false;
	}
	return true;
}

static void loadDataMap(std::map<std::string, float> &dataMap, std::ifstream &dataFile)
{
	std::string dateRate;
	getline(dataFile, dateRate); // pour perdre le "date,exchange_rate"
	do
	{
		getline(dataFile, dateRate);
		size_t pos = dateRate.find(",");
		if(pos != std::string::npos)
		{
			// separe la date et exchange rate
			std::string date = dateRate.substr(0, pos);
			std::string rateStr = dateRate.substr(pos + 1, dateRate.size());
			
			// ajoute a notre map la key date et la value exchange rate
			dataMap[date] = std::strtof(rateStr.c_str(), NULL);
		}
	} while (!dataFile.eof());
}

int main(int argc, char **argv)
{
	if(!checkArg(argc, argv)) { return 1; }

	// open les files quon a besoin
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		{ return (err_msg("Open file failed : ", argv[1])); }
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		{ return ( err_msg("Open file failed : data.csv", NULL)); }

	// crée la map key value de data
	std::map<std::string, float> dataMap;
	loadDataMap(dataMap, dataFile);
	// calculate les btc grace a la map
	if(!checkInputFile_nCalculate(dataMap, inputFile))
	{
		inputFile.close();
		dataFile.close();
		return 1;
	}

	// closes the files
	dataFile.close();
	inputFile.close();
	return 0;
}