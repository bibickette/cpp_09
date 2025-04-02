/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:14:14 by phwang            #+#    #+#             */
/*   Updated: 2025/04/02 19:06:56 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include "Color.hpp"

bool checkInputFile_nCalculate(std::map<std::string, float> dataMap, std::ifstream &inputFile);
bool checkDate(int lineNb, std::string date);
bool checkValue(int lineNb, std::string value);
bool err(int lineInputNb, std::string valueInput, std::string const reason);

#endif