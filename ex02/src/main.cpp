/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:19:38 by phwang            #+#    #+#             */
/*   Updated: 2025/04/03 19:02:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		cout << RED << "Please enter at least one argument" << RESET << endl;
		return 0;
	}
	PmergeMe(argv);
	return 0;
}