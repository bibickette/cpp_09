/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:43:14 by phwang            #+#    #+#             */
/*   Updated: 2025/04/03 00:18:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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

void RPN(std::string arg)
{
	std::stack<int> nB;
	rm_space(arg);
	int i = -1;
	while(arg[++i])
	{
		if(arg[i] == ' ')
		{ i++; }
		if(isdigit(arg[i]))
		{
			if(arg[i + 1] && arg[i + 1] != ' ')
			{
				std::cout << "you need to separate numbers because they only can be between 0 and 9" << std::endl;
				return ;
			}
			nB.push(arg[i] - '0');
		}
		else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '/' || arg[i] == '*')
		{
			if(arg[i + 1] && arg[i + 1] != ' ')
			{
				std::cout << "you need to separate operators" << std::endl;
				return ;
			}
			if(nB.size() < 2)
			{
				std::cout << "stack is too small to operate" << std::endl;
				return ;
			}
			int a = nB.top();
   			nB.pop();
    		int b = nB.top();
    		nB.pop();
			
			switch (arg[i])
			{
			case '+':
				nB.push(b + a);
				break;
			case '-':
				nB.push(b - a);
				break;
			case '/':
				if(a == 0)
				{
					std::cout << "you can't divide by 0" << std::endl;
					return;
				}
				nB.push(b / a);
				break;
			case '*':
				nB.push(b * a);
				break;
			default:
				return;
			}
		}
		else
		{
			std::cout << arg[i] << " invalid value" << std::endl;
			return;
		}
	}
	if(nB.size() != 1)
	{
		std::cout << "missing operator" << std::endl;
		return ;
	}
	std::cout << nB.top() << std::endl;
}
