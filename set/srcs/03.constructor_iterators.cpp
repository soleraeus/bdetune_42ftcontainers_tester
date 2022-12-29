#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <list>
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
		volatile int	x = 0;
		std::cout << "*******   int set iterator constructor   *******" << std::endl;
		{
			int	tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = i;
			}
			{
				NAMESPACE::set<int>	test(tab, tab+25);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		std::cout << "*******   ConstClass<int> set iterator constructor   *******" << std::endl;
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
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());

				if (!test.size())
					x += 1;
				else
					x += 2;

			}
		}
		std::cerr << x << std::endl;
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	inttab[500];
		std::list<ConstClass<int> > Consttab;
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(ConstClass<int>(i));
		}
		for (int i = 50; i > 25; i--)
		{
			Consttab.push_back(ConstClass<int>(i));
		}
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(ConstClass<int>(i));
		}

		volatile int	x = 0;
		timer			timing;

		std::cout << "benchmark" << std::endl;
		{
			for (volatile int i = 0; i < 10000; i++)
			{
				NAMESPACE::set<int>	test(inttab, inttab+500);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		{
			for (volatile int i = 0; i < 10000; i++)
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > > test(Consttab.begin(), Consttab.end(), customCompare<ConstClass<int> >());

				if (!test.size())
					x += 1;
				else
					x += 2;

			}
		}
		std::cout << x << std::endl;
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
