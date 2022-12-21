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
#include "ConstClass.hpp"
#include "customCompare.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing int map   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::map<int, int>	test;

			test.insert(test.begin(), NAMESPACE::pair<int, int>(42, 42));
			test.insert(test.end(), NAMESPACE::pair<int, int>(666, 9));
			test.insert(test.end(), NAMESPACE::pair<int, int>(666, -9));
			test.insert(test.end(), NAMESPACE::pair<int, int>(13, 11));
			test.insert(test.begin(), NAMESPACE::pair<int, int>(-5, -7));
			for (NAMESPACE::map<int, int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
		}
		std::cout << "*******   Testing ConstClass<int> map   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >			test;
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator			ender = test.end();
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator			beg;

			test.insert(test.end(), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(42), ConstClass<int>(11)));
			beg = test.insert(test.begin(), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-6), ConstClass<int>(56)));
			test.insert(test.begin(), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-6), ConstClass<int>(85)));
			test.insert(test.begin(), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(7), ConstClass<int>(8)));

			for (; beg != test.end(); beg++)
			{
				std::cout << beg->first << " : " << beg->second << std::endl;
			}
			std::cout << (--ender)->first << " : " << ender->second << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;

		for (int i = 0; i < 5000; i++)
		{
			if (i % 2)
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
			else
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-i), ConstClass<int>(i)));
		}
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 5000; loop++)
		{
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test;
			int	j = 0;
			for (std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > >::iterator start = tab.begin(); start != tab.end(); start++, j++)
			{
				if (j % 2)
					test.insert(test.end(), *start);
				else
					test.insert(test.begin(), *start);
			}
			std::cout << test.begin()->first << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
