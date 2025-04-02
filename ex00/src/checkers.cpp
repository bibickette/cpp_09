/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:05:56 by phwang            #+#    #+#             */
/*   Updated: 2025/04/02 23:41:22 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.hpp"

using std::cout;
using std::endl;

static bool checkDateFormat(int lineNb, std::string date)
{
	int i = -1;
	int tiret = 0;
	if(date.size() != 10)
	{
		return err(lineNb, date, "size of date needs to be 10 and format : XXXX-XX-XX");
	}
	while(date[++i])
	{
		if(date[i] == '-')
		{ tiret++;}
		if(!(date[i] >= '0' && date[i] <= '9') && date[i] != '-')
		{
			return err(lineNb, date, "date can contain only digits and \'-\'");
		}
	}
	if(tiret != 2 || date[4] != '-' || date[7] != '-')
	{
		return err(lineNb, date, "date needs to have two \'-\' and format is : XXXX-XX-XX");
	}
	return true;
}

static bool checkDateValue(int lineNb, std::string date)
{
	// check actual value of the date
	int year = atoi((date.substr(0, 4)).c_str()); // substr(position, nb de char a copier)
	int month = atoi((date.substr(5, 2)).c_str());
	int day = atoi((date.substr(8, 2)).c_str());
	
	if(year < 2009 || date < "2009-01-02")
	{
		return err(lineNb, date, "bictoin didn't exist this date");
	}
	else if(!(month > 0 && month < 13))
	{
		return err(lineNb, date, "this month doesn't exist on this planet");	
	}
	else if(!(day > 0 && day < 32))
	{
		return err(lineNb, date, "our months have between 1 and 31 days");	
	}
	// check month and day nb
	if((!(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
	&& !(day > 0 && day < 31))
	{
		return err(lineNb, date, "04, 06, 09 and 11 has between 1 and 30 days");	
	}
	std::tm timeStruct = {};
    timeStruct.tm_year = year - 1900; 
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;

    std::time_t t = std::mktime(&timeStruct);
    if (t == -1 || timeStruct.tm_year + 1900 != year || 
    timeStruct.tm_mon + 1 != month || timeStruct.tm_mday != day)
    {    return err(lineNb, date, "invalid date");}

	return true;	
}

bool checkDate(int lineNb, std::string date)
{
	if(!checkDateFormat(lineNb, date))
		{ return false; }
	if(!checkDateValue(lineNb, date))
		{ return false; }	
	return true;
}


bool checkValue(int lineNb, std::string value)
{
	if(value[0] == '.') // check le premier
	{
		return err(lineNb, value, "float format : XXXX.XX");
	}
	// check le bon format
	int point = 0;
	for (size_t i = 0; value[i]; i++)
	{
		if(!isdigit(value[i]) && value[i] != '.') // que des nb et .
		{
			return err(lineNb, value, "value can contains only digit and float format");
		}
		else if(value[i] == '.' && (!value[i + 1] || (value[i + 1] && !isdigit(value[i + 1]))))
		{
			// check si nb apres un point
			return err(lineNb, value, "float format : XXXX.XX");
		}
		if(value[i] == '.')
		{ point++; }
	}
	if(point > 1)
	{
		return err(lineNb, value, "float format : XXXX.XX");
	}
	if(value.size() > 5 || std::strtof(value.c_str(), NULL) > 1000.0f || std::strtof(value.c_str(), NULL) < 0.0f)
	{
		err(lineNb, value, "value need to be between 0 and 1000");
		return false;
	}
	return true;
}
