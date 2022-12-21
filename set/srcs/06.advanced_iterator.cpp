#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
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
		std::cout << "*******   Empty int set   *******" << std::endl;
		{
			NAMESPACE::set<int>				test;

			for (NAMESPACE::set<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   int set   *******" << std::endl;
		{
			int	tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = i;
			}
			NAMESPACE::set<int>				test(tab, tab+25);
			NAMESPACE::set<int>::iterator		tmp;

			for (NAMESPACE::set<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			tmp = test.begin();
			tmp++;
			std::cout << *(tmp++) << std::endl;
			std::cout << *tmp << std::endl;
			std::cout << *(++tmp) << std::endl;
			++tmp;
			for (NAMESPACE::set<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> set   *******" << std::endl;
		{
			std::list<ConstClass<int> > Consttab;
			for (int i = 0; i < 25; i++)
			{
				Consttab.push_back(ConstClass<int>(i));
			}
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >				test(Consttab.begin(), Consttab.end());
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator		tmp;
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::const_iterator		tmp_const;

			tmp = test.begin();
			std::cout << *tmp << std::endl;
			while (tmp != test.end())
				tmp++;
			tmp--;
			std::cout << *(tmp--) << std::endl;
			std::cout << *tmp << std::endl;
			tmp_const = test.begin();
			tmp = tmp_const;
			std::cout << *tmp << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	tab[25];
		for (int i = 0; i < 25; i++)
		{
			tab[i] =  i;
		}
		NAMESPACE::set<int>				inttest(tab, tab+25);
		std::list<ConstClass<int> > Consttab;
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(ConstClass<int>(i));
		}
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >				test(Consttab.begin(), Consttab.end());

		timer								timing;

		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 25000 ; loop++)
		{
			{
				NAMESPACE::set<int>::iterator			tmp;
				for (NAMESPACE::set<int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				tmp = inttest.begin();
				tmp++;
				std::cout << *(tmp++) << std::endl;
				std::cout << *tmp << std::endl;
				std::cout << *(++tmp) << std::endl;
				++tmp;
				for (NAMESPACE::set<int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator		tmp;

				tmp = test.begin();
				std::cout << *tmp << std::endl;
				while (tmp != test.end())
					tmp++;
				tmp--;
				std::cout << *tmp << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
