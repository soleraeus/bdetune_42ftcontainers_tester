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

			test.insert(42);
			test.insert(666);
			test.insert(666);
			test.insert(13);
			test.insert(-5);
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
			NAMESPACE::pair<NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator, bool>	ret;

			ret = test.insert(ConstClass<int>(42));
			std::cout << ret.second << std::endl;
			ret = test.insert(ConstClass<int>(-6));
			std::cout << ret.second << std::endl;
			beg = ret.first;
			ret = test.insert(ConstClass<int>(-6));
			std::cout << ret.second << std::endl;
			ret = test.insert(ConstClass<int>(7));
			std::cout << ret.second << std::endl;

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
		for (volatile int loop = 0; loop < 2500; loop++)
		{
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test;

			for (std::list<ConstClass<int> >::iterator start = tab.begin(); start != tab.end(); start++)
			{
				test.insert(*start);
			}
			std::cout << *(test.begin()) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
