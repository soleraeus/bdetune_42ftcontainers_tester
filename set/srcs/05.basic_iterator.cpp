#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>
#include "ConstClass.hpp"
#include "timer.hpp"
#include "customCompare.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   empty int set   *******" << std::endl;
		{
			NAMESPACE::set<int>	test;

			for (NAMESPACE::set<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> set   *******" << std::endl;
		{
			std::list<ConstClass<int> > tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(ConstClass<int>(i));
			}
			for (int i = 50; i > 25; i--)
			{
				tab.push_back(ConstClass<int>(i));
			}
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(ConstClass<int>(i));
			}
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
			for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<ConstClass<int> > tab;
		for (int i = 0; i < 25; i++)
		{
			tab.push_back(ConstClass<int>(i));
		}
		for (int i = 50; i > 25; i--)
		{
			tab.push_back(ConstClass<int>(i));
		}
		NAMESPACE::set<int>	inttest;
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	Consttest(tab.begin(), tab.end());

		timer							timing;
		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				for (NAMESPACE::set<int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
			{
				for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = Consttest.begin(); start != Consttest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
