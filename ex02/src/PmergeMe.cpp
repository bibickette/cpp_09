/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:22:37 by phwang            #+#    #+#             */
/*   Updated: 2025/04/03 19:00:49 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using std::cout;
using std::endl;

static bool isInt(std::string str)
{
    if (str.empty())
    {
        cout << RED << "arg can't be empty" << RESET << endl;
        return false;
    }
    else if (str.size() > 10 || (str > "2147483647" && str.size() == 10))
    {
        cout << RED << "arg has to be an int" << RESET << endl;
        return false;
    }
    return true;
}

static void display(std::vector<int> arg)
{
    for (unsigned long i = 0; i < arg.size(); i++)
    {
        cout << arg[i] << " ";
    }
}

std::vector<int> generate(size_t n)
{
    std::vector<int> jacobsthal;
   
    if (n == 0)
        return jacobsthal;
    
    size_t j0 = 0;
    jacobsthal.push_back(j0);
    
    size_t j1 = 1;
    if (j1 < n && (jacobsthal.empty() || j1 != (size_t)jacobsthal.back()))
    {
        jacobsthal.push_back(j1);
    }
   
    size_t jn = j1 + 2 * j0;
    while (jn < n)
    {
        if (jacobsthal.empty() || jn != (size_t)jacobsthal.back())
        {
            jacobsthal.push_back(jn);
        }
        j0 = j1;
        j1 = jn;
        jn = j1 + 2 * j0;
    }
    return jacobsthal;
}

static void jacobsthal(std::vector<int> &smaller, std::vector<int> &larger)
{
    std::vector<int>::iterator iterator;
    std::vector<int> jacobsthal = generate(smaller.size());
    std::vector<bool> isInserted(smaller.size(), false);

    // use jacobsthal pour inserer
    for (size_t i = 0; i < jacobsthal.size(); i++)
    {
        int index = jacobsthal[i];
        std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[index]);
        larger.insert(pos, smaller[index]);
        isInserted[index] = true;
    }
    // insere le reste
    for (size_t i = 0; i < smaller.size(); i++)
    {
        if(!isInserted[i])
        {
          iterator = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
          larger.insert(iterator, smaller[i]);
        }
    }
}

static void fordJohnson(std::vector<int> &arg)
{
    std::vector<int> smaller;
    std::vector<int> larger;
    
    if (arg.size() < 2)
    {
        return;
    }
    for (size_t i = 0; i < arg.size() - 1; i += 2)
    {
        if (arg[i] < arg[i + 1])
        {
            smaller.push_back(arg[i]);
            larger.push_back(arg[i + 1]);
        }
        else
        {
            smaller.push_back(arg[i + 1]);
            larger.push_back(arg[i]);
        }
    }
    if (arg.size() % 2 != 0)
    {
        larger.push_back(arg[arg.size() - 1]);
    }
    fordJohnson(larger);
    jacobsthal(smaller, larger);
    arg = larger;
}

// --------------------- deque

std::deque<int> generate_deque(size_t n)
{
    std::deque<int> jacobsthal;
   
    if (n == 0)
        return jacobsthal;
    
    size_t j0 = 0;
    jacobsthal.push_back(j0);
    
    size_t j1 = 1;
    if (j1 < n && (jacobsthal.empty() || j1 != (size_t)jacobsthal.back()))
    {
        jacobsthal.push_back(j1);
    }
   
    size_t jn = j1 + 2 * j0;
    while (jn < n)
    {
        if (jacobsthal.empty() || jn != (size_t)jacobsthal.back())
        {
            jacobsthal.push_back(jn);
        }
        j0 = j1;
        j1 = jn;
        jn = j1 + 2 * j0;
    }
    return jacobsthal;
}

static void jacobsthal(std::deque<int> &smaller, std::deque<int> &larger)
{
    std::deque<int>::iterator iterator;
    std::deque<int> jacobsthal = generate_deque(smaller.size());
    std::deque<bool> isInserted(smaller.size(), false);

    // use jacobsthal pour inserer
    for (size_t i = 0; i < jacobsthal.size(); i++)
    {
        int index = jacobsthal[i];
        std::deque<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
        larger.insert(pos, smaller[index]);
        isInserted[index] = true;
    }
    // insere le reste
    for (size_t i = 0; i < smaller.size(); i++)
    {
        if(!isInserted[i])
        {
          iterator = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
          larger.insert(iterator, smaller[i]);
        }
    }
}

static void fordJohnson(std::deque<int> &arg)
{
    std::deque<int> smaller;
    std::deque<int> larger;
    
    if (arg.size() < 2)
    {
        return;
    }
    for (size_t i = 0; i < arg.size() - 1; i += 2)
    {
        if (arg[i] < arg[i + 1])
        {
            smaller.push_back(arg[i]);
            larger.push_back(arg[i + 1]);
        }
        else
        {
            smaller.push_back(arg[i + 1]);
            larger.push_back(arg[i]);
        }
    }
    if (arg.size() % 2 != 0)
    {
        larger.push_back(arg[arg.size() - 1]);
    }
    fordJohnson(larger);
    jacobsthal(smaller, larger);
    arg = larger;
}

void PMergeMe(char **argv)
{
    std::vector<int> arg;
    std::deque<int> arg2;
    
    int i = 0;
    while(argv[++i])
    {
        int j = -1;
        while(argv[i][++j])
        {
            if(!isdigit(argv[i][j]))
            {
                cout << RED << "only digits are accepted" << RESET << endl;
                return;
            }
        }
    }
    // check and keep arg
    i = 1;
    while (argv[i])
    {
        if (!isInt(argv[i]))
        {
            return;
        }
        int nb = atoi(argv[i]);
        if (nb < 0)
        {
            cout << RED << "the argument can only be positive number" << RESET << endl;
            return;
        }
        arg.push_back(nb);
        arg2.push_back(nb);
        i++;
    }
    // check nb darg
    if (arg.size() < 2)
    {
        cout << RED << "needs to have at least 2 arg" << RESET << endl;
        return;
    }

    // afficher la stack before trie
    cout << "Before : ";
    display(arg);
    cout << endl;
    // take the time and trier
    std::clock_t start = std::clock();
    fordJohnson(arg);
    std::clock_t end = std::clock();
    
    cout << endl;
    cout << "After : ";
    display(arg);
    cout << endl;
    
    
    double time = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time to process a range of " << arg.size() << " elements with std::vector<int> : ";
    cout << time << " µs" << endl;
    
    start = std::clock();
    fordJohnson(arg2);
    end = std::clock();
    

    time = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time to process a range of " << arg2.size() << " elements with std::deque<int> : ";
    cout << time << " µs" << endl;
}
