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
		std::cout << "*******   int set find   *******" << std::endl;
		{
			int	tab[500];
			for (int i = 0; i < 500; i++)
			{				
				tab[i] = (i % 2) ? -i : i;
			}
			{
				NAMESPACE::set<int>					test(tab, tab+500);
				NAMESPACE::set<int>::iterator			it;
				NAMESPACE::set<int>::const_iterator	it_const;

				std::cout << (((it = test.find(1)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(2)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(-1000)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(499)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(498)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(-1)) != test.end()) ? *it : 0) << std::endl;
				std::cout << (((it = test.find(0)) != test.end()) ? *it : 0) << std::endl;

				std::cout << (((it_const = test.find(1)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(2)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(-1000)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(499)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(498)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(-1)) != test.end()) ? *it_const : 0) << std::endl;
				std::cout << (((it_const = test.find(0)) != test.end()) ? *it_const : 0) << std::endl;

			}
		}
		std::cout << "*******   ConstClass<int> set find   *******" << std::endl;
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
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator			it;
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::const_iterator	it_const;


				std::cout << (((it = test.find(ConstClass<int>(1))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(-2))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(-1000))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(49))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(50))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(21))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;
				std::cout << (((it = test.find(ConstClass<int>(0))) != test.end()) ? *it : ConstClass<int>(0)) << std::endl;

				std::cout << (((it_const = test.find(ConstClass<int>(1))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(-2))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(-1000))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(49))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(50))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(21))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;
				std::cout << (((it_const = test.find(ConstClass<int>(0))) != test.end()) ? *it_const : ConstClass<int>(0)) << std::endl;

			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	inttab[5000];
		for (int i = 0; i < 5000; i++)
		{				
			inttab[i] = (i % 2) ? -i : i;
		}
		NAMESPACE::set<int>	test(inttab, inttab+5000);

		std::list<ConstClass<int> > tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(ConstClass<int>(i));
		}
		for (int i = 5000; i > 2500; i--)
		{
			tab.push_back(ConstClass<int>(i));
		}
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	testConst(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
		NAMESPACE::set<int>::iterator			it;
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator			itConstClass;




		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100000; loop++)
		{
			std::cout << (((it = test.find(1)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(2)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-1000)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(499)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(498)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-1)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(0)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(100)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(22650)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-100120)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(99)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(1198)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(4998)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-4998)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(156)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-2661)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-156)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(4994)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(498569)) != test.end()) ? *it : 0) << std::endl;
			std::cout << (((it = test.find(-15464)) != test.end()) ? *it : 0) << std::endl;

			std::cout << (((itConstClass = testConst.find(ConstClass<int>(1))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(-2))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(-1000))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(4999))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(42))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(-50000))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(156))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(965))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(1000))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(5000))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(-1))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;
			std::cout << (((itConstClass = testConst.find(ConstClass<int>(568))) != testConst.end()) ? *itConstClass : ConstClass<int>(0)) << std::endl;


		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
