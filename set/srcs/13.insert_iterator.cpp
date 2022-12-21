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
		std::cout << "*******   Testing ConstClass<int> set   *******" << std::endl;
		{
			std::list<ConstClass<int> > tab;

			for (int i = 0; i < 500; i++)
			{
				if (i % 2)
					tab.push_back(ConstClass<int>(-i));
				else
					tab.push_back(ConstClass<int>(i));
			}
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >			test;

			test.insert(tab.begin(),tab.end());

			for (NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator beg = test.begin() ; beg != test.end(); beg++)
			{
				std::cout << *beg << std::endl;
			}
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
			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >			test;

			test.insert(tab.begin(),tab.end());
			std::cout << *(test.begin()) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
