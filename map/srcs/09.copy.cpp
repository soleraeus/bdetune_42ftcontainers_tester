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
		NAMESPACE::pair<int, int>	inttab[50];
		for (int i = 0; i < 25; i++)
		{
			inttab[i] = NAMESPACE::pair<int, int>(i, i);
		}
		for (int i = 25; i < 50; i++)
		{
			inttab[i] = NAMESPACE::pair<int, int>(-i, -i);
		}
		std::cout << "*******   int map   *******" << std::endl;
		{
			NAMESPACE::map<int, int>*	test = new NAMESPACE::map<int, int>(inttab, inttab+50);
			NAMESPACE::map<int, int>	test1(*test);

			for (NAMESPACE::map<int, int>::iterator start = test->begin(); start != test->end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			delete test;
			for (NAMESPACE::map<int, int>::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}

		}
		std::cout << "*******   ConstClass<int> map   *******" << std::endl;
		{
			std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > >					tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
			}
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test1(++(tab.begin()), --(tab.end()));
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test2(test1);
			for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test2.begin(); start != test2.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			test1 = test2;
			for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			std::cout << (test1.size() == test2.size()) << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>	inttab[250];
		for (int i = 0; i < 125; i++)
		{
			inttab[i] = NAMESPACE::pair<int, int>(i, i);
		}
		for (int i = 125; i < 250; i++)
		{
			inttab[i] = NAMESPACE::pair<int, int>(-i, -i);
		}
		NAMESPACE::map<int, int>	inttest(inttab, inttab+250);
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > >	tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
		}
		NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
		timer							timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				NAMESPACE::map<int, int>	test1(inttest);

				std::cout << (inttest.begin())->second << std::endl;
				std::cout << (test1.begin())->second << std::endl;
			}
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test2;
				test2 = test;
				std::cout << (test.begin())->first << std::endl;
				std::cout << (test2.begin())->first << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
