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
		std::cout << "*******   int map count   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>	tab[500];
			for (int i = 0; i < 500; i++)
			{				
				tab[i] = (i % 2) ? NAMESPACE::pair<int, int>(-i, i) : NAMESPACE::pair<int, int>(i, i);
			}
			{
				NAMESPACE::map<int, int>	test(tab, tab+500);

				std::cout << test.count(1) << std::endl;
				std::cout << test.count(2) << std::endl;
				std::cout << test.count(-1000) << std::endl;
				std::cout << test.count(499) << std::endl;
				std::cout << test.count(498) << std::endl;
				std::cout << test.count(-1) << std::endl;
				std::cout << test.count(0) << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> map count   *******" << std::endl;
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

				std::cout << test.count(ConstClass<int>(1)) << std::endl;
				std::cout << test.count(ConstClass<int>(-2)) << std::endl;
				std::cout << test.count(ConstClass<int>(-1000)) << std::endl;
				std::cout << test.count(ConstClass<int>(49)) << std::endl;
				std::cout << test.count(ConstClass<int>(50)) << std::endl;
				std::cout << test.count(ConstClass<int>(21)) << std::endl;
				std::cout << test.count(ConstClass<int>(0)) << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>	inttab[5000];
		for (int i = 0; i < 5000; i++)
		{				
			inttab[i] = (i % 2) ? NAMESPACE::pair<int, int>(-i, i) : NAMESPACE::pair<int, int>(i, i);
		}
		NAMESPACE::map<int, int>	test(inttab, inttab+5000);

		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 5000; i > 2500; i--)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	testConst(tab.begin(), tab.end(), customCompare<ConstClass<int> >());


		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100000; loop++)
		{
			std::cout << test.count(1) << std::endl;
			std::cout << test.count(2) << std::endl;
			std::cout << test.count(-1000) << std::endl;
			std::cout << test.count(499) << std::endl;
			std::cout << test.count(498) << std::endl;
			std::cout << test.count(-1) << std::endl;
			std::cout << test.count(0) << std::endl;
			std::cout << test.count(100) << std::endl;
			std::cout << test.count(22650) << std::endl;
			std::cout << test.count(-100120) << std::endl;
			std::cout << test.count(99) << std::endl;
			std::cout << test.count(1198) << std::endl;
			std::cout << test.count(4998) << std::endl;
			std::cout << test.count(-4998) << std::endl;
			std::cout << test.count(156) << std::endl;
			std::cout << test.count(-2661) << std::endl;
			std::cout << test.count(-156) << std::endl;
			std::cout << test.count(4994) << std::endl;
			std::cout << test.count(498569) << std::endl;
			std::cout << test.count(-15464) << std::endl;

			std::cout << testConst.count(ConstClass<int>(1)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(-2)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(-1000)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(4999)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(42)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(-50000)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(156)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(965)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(1000)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(5000)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(-1)) << std::endl;
			std::cout << testConst.count(ConstClass<int>(568)) << std::endl;


		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
