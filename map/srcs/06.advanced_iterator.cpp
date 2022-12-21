#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
#endif
#include <list>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ConstClass.hpp"
#include "timer.hpp"
#include "customCompare.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Empty int map   *******" << std::endl;
		{
			NAMESPACE::map<int, int>				test;

			for (NAMESPACE::map<int, int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
		}
		std::cout << "*******   int map   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>	tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = NAMESPACE::pair<int, int>(i, i);
			}
			NAMESPACE::map<int, int>				test(tab, tab+25);
			NAMESPACE::map<int, int>::iterator		tmp;

			for (NAMESPACE::map<int, int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			tmp = test.begin();
			tmp++;
			tmp->second = 0;
			++tmp;
			++tmp;
			tmp->second = -1;
			(--tmp)->second = 59;
			for (NAMESPACE::map<int, int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> map   *******" << std::endl;
		{
			std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > Consttab;
			for (int i = 0; i < 25; i++)
			{
				Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >				test(Consttab.begin(), Consttab.end());
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator		tmp;

			tmp = test.begin();
			std::cout << (*tmp).first << std::endl;
			while (tmp != test.end())
				tmp++;
			tmp--;
			std::cout << (*tmp).first << " : " << tmp->second << std::endl;
			tmp->second = ConstClass<int>(42);
			std::cout << (*tmp).first << " : " << tmp->second << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>	tab[25];
		for (int i = 0; i < 25; i++)
		{
			tab[i] = NAMESPACE::pair<int, int>(i, i);
		}
		NAMESPACE::map<int, int>				inttest(tab, tab+25);
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > Consttab;
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >				test(Consttab.begin(), Consttab.end());

		timer								timing;

		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 25000 ; loop++)
		{
			{
				NAMESPACE::map<int, int>::iterator			tmp;
				for (NAMESPACE::map<int, int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << start->first << " : " << start->second << std::endl;
				}
				tmp = inttest.begin();
				tmp++;
				tmp->second = 0;
				++tmp;
				++tmp;
				tmp->second = -1;
				(--tmp)->second = 59;
				for (NAMESPACE::map<int, int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << start->first << " : " << start->second << std::endl;
				}
			}
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator		tmp;

				tmp = test.begin();
				std::cout << (*tmp).first << std::endl;
				while (tmp != test.end())
					tmp++;
				tmp--;
				std::cout << (*tmp).first << " : " << tmp->second << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
