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
#include <memory>
#include "ConstClass.hpp"
#include "timer.hpp"
#include "customCompare.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   int set default constructor   *******" << std::endl;
		{
			NAMESPACE::set<int>	test;
			std::cout << test.size() << std::endl;
			std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   std::string set default constructor   *******" << std::endl;
		{
			NAMESPACE::set<std::string>	test;
			std::cout << test.size() << std::endl;
			std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
			std::cout << test.empty() << std::endl;

		}
		std::cout << "*******   ConstClass<int> set default constructor   *******" << std::endl;
		{
			NAMESPACE::set<ConstClass<int> >	test;
			std::cout << test.size() << std::endl;
			std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   ConstClass<int> set iterator constructor   *******" << std::endl;
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

			NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
			std::cout << test.size() << std::endl;
			std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
			std::cout << test.empty() << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
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

		timer	timing;
		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 25000; loop++)
		{
			{
				NAMESPACE::set<int>	test;
				std::cout << test.size() << std::endl;
				std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::set<std::string>	test;
				std::cout << test.size() << std::endl;
				std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
				std::cout << test.empty() << std::endl;

			}
			{
				NAMESPACE::set<ConstClass<int> >	test;
				std::cout << test.size() << std::endl;
				std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end());
				std::cout << test.size() << std::endl;
				std::cout << (test.max_size() < test.size() ? "Wrong max size" : "Max size OK") << std::endl;
				std::cout << test.empty() << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
