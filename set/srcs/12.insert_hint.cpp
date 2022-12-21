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
#include "ConstClass.hpp"
#include "customCompare.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing int set   *******" << std::endl;
		{
			NAMESPACE::set<int>	test;

			test.insert(test.begin(), 42);
			test.insert(test.end(), 666);
			test.insert(test.end(), 666);
			test.insert(test.end(), 13);
			test.insert(test.begin(), -5);
			for (NAMESPACE::set<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   Testing ConstClass<int> set   *******" << std::endl;
		{
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >			test;
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator			ender = test.end();
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator			beg;

			test.insert(test.end(), ConstClass<int>(42));
			beg = test.insert(test.begin(), ConstClass<int>(-6));
			test.insert(test.begin(), ConstClass<int>(-6));
			test.insert(test.begin(), ConstClass<int>(7));

			for (; beg != test.end(); beg++)
			{
				std::cout << *beg << std::endl;
			}
			std::cout << *(--ender) << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<ConstClass<int> > tab;

		for (int i = 0; i < 5000; i++)
		{
			if (i % 2)
				tab.push_back(ConstClass<int>(-i));
			else
				tab.push_back(ConstClass<int>(i));
		}
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 5000; loop++)
		{
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test;
			int	j = 0;
			for (std::list<ConstClass<int> >::iterator start = tab.begin(); start != tab.end(); start++, j++)
			{
				if (j % 2)
					test.insert(test.end(), *start);
				else
					test.insert(test.begin(), *start);
			}
			std::cout << *(test.begin()) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
