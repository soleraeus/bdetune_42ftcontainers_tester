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
		int	inttab[50];
		for (int i = 0; i < 25; i++)
		{
			inttab[i] = i;
		}
		for (int i = 25; i < 50; i++)
		{
			inttab[i] = -i;
		}
		std::cout << "*******   int set   *******" << std::endl;
		{
			NAMESPACE::set<int>*	test = new NAMESPACE::set<int>(inttab, inttab+50);
			NAMESPACE::set<int>	test1(*test);

			for (NAMESPACE::set<int>::iterator start = test->begin(); start != test->end(); start++)
			{
				std::cout << *start << std::endl;
			}
			delete test;
			for (NAMESPACE::set<int>::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << *start << std::endl;
			}

		}
		std::cout << "*******   ConstClass<int> set   *******" << std::endl;
		{
			std::list<ConstClass<int> >					tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(ConstClass<int>(-i));
			}
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test1(++(tab.begin()), --(tab.end()));
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test2(test1);
			for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test2.begin(); start != test2.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test1 = test2;
			for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << (test1.size() == test2.size()) << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	inttab[250];
		for (int i = 0; i < 125; i++)
		{
			inttab[i] = i;
		}
		for (int i = 125; i < 250; i++)
		{
			inttab[i] = -i;
		}
		NAMESPACE::set<int>	inttest(inttab, inttab+250);
		std::list<ConstClass<int> >	tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(ConstClass<int>(-i));
		}
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
		timer							timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				NAMESPACE::set<int>	test1(inttest);

				std::cout << *(inttest.begin()) << std::endl;
				std::cout << *(test1.begin()) << std::endl;
			}
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test2;
				test2 = test;
				std::cout << *(test.begin()) << std::endl;
				std::cout << *(test2.begin()) << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
