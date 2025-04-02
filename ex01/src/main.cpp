/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:43:25 by phwang            #+#    #+#             */
/*   Updated: 2025/04/02 23:53:28 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "this programme take only one argument as a string" << std::endl;
		return 0;
	}
	std::string arg = argv[1];
	if(arg.empty())
	{
		std::cout << "Argument can not be empty" << std::endl;
		return 0;
	}	
	RPN(arg);
	return 0;
}
