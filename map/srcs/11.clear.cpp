#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
#endif
#include <list>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <memory>
#include "ConstClass.hpp"
#include "customCompare.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing int map   *******" << std::endl;
		{
			NAMESPACE::map<int, int>	test;
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			
			test.clear();

			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   Testing ConstClass<int> map   *******" << std::endl;
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
		for (int i = 0; i < 50; i++)
		{
			if (i % 2)
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
			else
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-i), ConstClass<int>(i)));
		}
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			test.clear();
			std::cout << test.empty() << std::endl;
			std::cout << test.size() << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
		for (int i = 0; i < 250; i++)
		{
			if (i % 2)
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(-i)));
			else
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(-i), ConstClass<int>(i)));
		}


		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 25000; loop++)
		{
			{
				NAMESPACE::map<int, int>	test;
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
				
				test.clear();

				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
				test.clear();
				std::cout << test.empty() << std::endl;
				std::cout << test.size() << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
