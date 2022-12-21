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
		std::cout << "*******   Testing ConstClass<int> map   *******" << std::endl;
		{
			std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;

			for (int i = 0; i < 500; i++)
			{
				if (i % 2)
					tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
				else
					tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-i), ConstClass<int>(i)));
			}
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >			test;

			test.insert(tab.begin(),tab.end());

			for (NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator beg = test.begin() ; beg != test.end(); beg++)
			{
				std::cout << beg->first << " : " << beg->second << std::endl;
			}
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
		for (volatile int loop = 0; loop < 2500; loop++)
		{
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >			test;

			test.insert(tab.begin(),tab.end());
			std::cout << test.begin()->first << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
