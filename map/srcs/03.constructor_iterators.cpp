#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
		std::cout << "*******   int map iterator constructor   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>	tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = NAMESPACE::pair<int, int>(i, i);
			}
			{
				NAMESPACE::map<int, int>	test(tab, tab+25);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		std::cout << "*******   ConstClass<int> map iterator constructor   *******" << std::endl;
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
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());

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
		NAMESPACE::pair<int, int>	inttab[500];
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > Consttab;
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 50; i > 25; i--)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 0; i < 25; i++)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}

		volatile int	x = 0;
		timer			timing;

		std::cout << "benchmark" << std::endl;
		{
			for (volatile int i = 0; i < 10000; i++)
			{
				NAMESPACE::map<int, int>	test(inttab, inttab+500);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		{
			for (volatile int i = 0; i < 10000; i++)
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > > test(Consttab.begin(), Consttab.end(), customCompare<ConstClass<int> >());

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
