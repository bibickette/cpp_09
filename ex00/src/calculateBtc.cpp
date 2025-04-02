/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculateBtc.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:13:31 by phwang            #+#    #+#             */
/*   Updated: 2025/04/02 21:50:19 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.hpp"

using std::cout;
using std::endl;

bool err(int lineInputNb, std::string valueInput, std::string const reason)
{
	cout << RED << "line " << RESET;
			cout << lineInputNb << RED << " in input file : " << RESET << valueInput << endl;
			cout << RED << "	bad input : " << BLUE << reason << RESET << endl;
	return false;
}

static void rm_space(std::string &value)
{
	// rm les espaces si yen a au debut et a la fin
	if(value[0] == ' ')
	{
		value = value.substr(1, value.size());
	}
	else if(value[value.size() - 1] == ' ')
	{
		value = value.substr(0, value.size() - 1);	
	}
	else
	{ return; }
	rm_space(value);
}

static float calculate(std::map<std::string, float> dataMap, std::string key, float value)
{
	std::map<std::string, float>::iterator iterator = dataMap.begin();
	if(key > iterator->first && key <= (dataMap.rbegin())->first)
	{
		while(iterator != dataMap.end())
		{
			if(iterator->first < key) // en gros la on va chercher literateur qui est juste au dessus de ma date
			{
				iterator++;
			}
			else
			{ break; }
		}
		if (iterator->first != key) // je recule a la val den dessous pour avoir la plus proche de ma date, et jexclu si c ma date
		{
			iterator--;
		}
	}
	else if (key >= (dataMap.rbegin())->first)
	{
		iterator = --dataMap.end();
	}
	return value * iterator->second;
}

bool checkInputFile_nCalculate(std::map<std::string, float> dataMap, std::ifstream &inputFile)
{
	std::string dateValueInput; // va keep la line du file
	// check la premiere ligne
	getline(inputFile, dateValueInput); // pour perdre le "date | value"
	if(dateValueInput != "date | value")
	{
		cout << RED << "First line of Input File has to be this exact string : \"date | value\"" << RESET << endl;
		return false;
	}
	int lineInputNb = 1;
	//check chacke date and value
	do
	{
		getline(inputFile, dateValueInput);
		++lineInputNb;
		size_t pos = dateValueInput.find("|");
		if(pos != std::string::npos) // check bon format date | value
		{
			// separe les valeurs dans 2 string avant danalyser
			std::string date = dateValueInput.substr(0, pos);
			std::string valueStr = dateValueInput.substr(pos + 1, dateValueInput.size());
			rm_space(date);
			rm_space(valueStr);
			
			// check une bonne date et une bonne value
			if(valueStr.empty())
			{
				err(lineInputNb, valueStr, "the value can't be empty");
			}
			else if(checkDate(lineInputNb, date) && checkValue(lineInputNb, valueStr))
			{
				cout << date << " => " << std::strtof(valueStr.c_str(), NULL) << " = ";
				cout << calculate(dataMap, date, std::strtof(valueStr.c_str(), NULL)) << endl;
			}
		}
		else
		{
			err(lineInputNb, dateValueInput, "wrong format date | value");
		}
	} while (!inputFile.eof());
	return true;
}
