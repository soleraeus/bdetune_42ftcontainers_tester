#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <ctime>
#include <cstdlib>
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
		std::cout << "*******   empty int set   *******" << std::endl;
		{
			NAMESPACE::set<int>						test;
			NAMESPACE::set<int>::reverse_iterator		tmp = test.rbegin();

			for (NAMESPACE::set<int>::const_reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << ( tmp == test.rend() ? "true" : "false") << std::endl;
		}
		std::cout << "*******   int set   *******" << std::endl;
		{
			int				tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = -i;
			}
			NAMESPACE::set<int>						test(tab, tab+25);
			NAMESPACE::set<int>::iterator				tmp = test.begin();
			NAMESPACE::set<int>::reverse_iterator		rtmp(tmp);

			for (NAMESPACE::set<int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << ( rtmp == test.rend() ? "true" : "false") << std::endl;

			std::cout << *(--rtmp) << std::endl;
			std::cout << *(rtmp--) << std::endl;
			std::cout << *rtmp << std::endl;
			rtmp--;
			for (NAMESPACE::set<int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << *((++rtmp)++) << " & " << *rtmp << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int				tab[50];
		for (int i = 0; i < 50; i++)
		{
			tab[i] = -i;
		}
		timer										timing;

		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 25000; loop++)
		{
			NAMESPACE::set<int>						test(tab, tab+50);
			NAMESPACE::set<int>::iterator				tmp = test.begin();
			NAMESPACE::set<int>::reverse_iterator		rtmp(tmp);

			for (NAMESPACE::set<int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << ( rtmp == test.rend() ? "true" : "false") << std::endl;
			std::cout << *(--rtmp) << std::endl;
			std::cout << *(rtmp--) << std::endl;
			std::cout << *rtmp << std::endl;
			rtmp--;
			std::cout << *((++rtmp)++) << " & " << *rtmp << std::endl;


		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
