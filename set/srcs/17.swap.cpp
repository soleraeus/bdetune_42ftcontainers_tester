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
		{
			int	tab1[500];
			int	tab2[500];
			for (int i = 0; i < 500; i++)
			{
				tab1[i] = i;
			}
			for (int i = 1000; i < 1500; i++)
			{
				tab2[i - 1000] = i;
			}
			{
				std::cout << "*******   member swap   *******" << std::endl;
				NAMESPACE::set<int>			test1(tab1, tab1+500);
				NAMESPACE::set<int>			test2(tab2, tab2+500);
				NAMESPACE::set<int>::iterator	it1 = test1.begin();
				NAMESPACE::set<int>::iterator	it2 = test2.begin();

				std::cout << *it1 << std::endl;
				std::cout << *it2 << std::endl;
				it1++;
				test1.swap(test2);

				std::cout << *it1 << std::endl;
				std::cout << *it2 << std::endl;
				
				for ( ; it1 != test2.end(); it1++)
				{
					std::cout << *it1 << std::endl;
				}	
				for ( ; it2 != test1.end(); it2++)
				{
					std::cout << *it2 << std::endl;
				}
				
				std::cout << "*******   Non-member swap   *******" << std::endl;
				it1 = test1.begin();
				it2 = test2.begin();

				std::cout << *it1 << std::endl;
				std::cout << *it2 << std::endl;
				it1++;
				NAMESPACE::swap(test1, test2);

				std::cout << *it1 << std::endl;
				std::cout << *it2 << std::endl;
				
				for ( ; it1 != test2.end(); it1++)
				{
					std::cout << *it1 << std::endl;
				}	
				for ( ; it2 != test1.end(); it2++)
				{
					std::cout << *it2 << std::endl;
				}

			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	tab1[1000];
		int	tab2[1000];
		for (int i = 0; i < 1000; i++)
		{
			tab1[i] = i;
		}
		for (int i = 2000; i < 3000; i++)
		{
			tab2[i - 2000] = i;
		}
		NAMESPACE::set<int>			test1(tab1, tab1+1000);
		NAMESPACE::set<int>			test2(tab2, tab2+1000);


		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 500000; loop++)
		{
			std::cout << *(test1.begin()) << std::endl; 
			std::cout << *(test2.begin()) << std::endl; 

			test1.swap(test2);

			std::cout << *(test1.begin()) << std::endl; 
			std::cout << *(test2.begin()) << std::endl; 

			NAMESPACE::swap(test1, test2);

			std::cout << *(test1.begin()) << std::endl; 
			std::cout << *(test2.begin()) << std::endl; 
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
