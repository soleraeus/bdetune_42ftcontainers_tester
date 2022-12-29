#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
		std::cout << "*******   empty int map   *******" << std::endl;
		{
			NAMESPACE::map<int, int>	test;

			for (NAMESPACE::map<int, int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> map   *******" << std::endl;
		{
			std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			for (int i = 50; i > 25; i--)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
			for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
		for (int i = 0; i < 25; i++)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 50; i > 25; i--)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		NAMESPACE::map<int, int>	inttest;
		NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	Consttest(tab.begin(), tab.end());

		timer							timing;
		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				for (NAMESPACE::map<int, int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << start->first << " : " << start->second << std::endl;
				}
			}
			{
				for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = Consttest.begin(); start != Consttest.end(); start++)
				{
					std::cout << start->first << " : " << start->second << std::endl;
				}
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
