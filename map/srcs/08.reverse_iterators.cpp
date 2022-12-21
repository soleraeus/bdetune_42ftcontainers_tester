#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
		std::cout << "*******   empty int map   *******" << std::endl;
		{
			NAMESPACE::map<int, int>						test;
			NAMESPACE::map<int, int>::reverse_iterator		tmp = test.rbegin();

			for (NAMESPACE::map<int, int>::const_reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			std::cout << ( tmp == test.rend() ? "true" : "false") << std::endl;
		}
		std::cout << "*******   int map   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>				tab[25];
			for (int i = 0; i < 25; i++)
			{
				tab[i] = NAMESPACE::pair<int, int>(-i, -i);
			}
			NAMESPACE::map<int, int>						test(tab, tab+25);
			NAMESPACE::map<int, int>::iterator				tmp = test.begin();
			NAMESPACE::map<int, int>::reverse_iterator		rtmp(tmp);

			for (NAMESPACE::map<int, int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			std::cout << ( rtmp == test.rend() ? "true" : "false") << std::endl;
			rtmp--;
			rtmp->second = 99;
			--rtmp;
			rtmp->second = 42;
			--rtmp;
			for (NAMESPACE::map<int, int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			std::cout << ((++rtmp)++)->second << " & " << (*rtmp).second << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>				tab[50];
		for (int i = 0; i < 50; i++)
		{
			tab[i] = NAMESPACE::pair<int, int>(-i, -i);
		}
		timer										timing;

		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 25000; loop++)
		{
			NAMESPACE::map<int, int>						test(tab, tab+50);
			NAMESPACE::map<int, int>::iterator				tmp = test.begin();
			NAMESPACE::map<int, int>::reverse_iterator		rtmp(tmp);

			for (NAMESPACE::map<int, int>::reverse_iterator start = test.rbegin(); start != test.rend(); start++)
			{
				std::cout << start->first << " : " << start->second << std::endl;
			}
			std::cout << ( rtmp == test.rend() ? "true" : "false") << std::endl;
			rtmp--;
			rtmp->second = 0;
			--rtmp;
			rtmp->second = -1;
			--rtmp;
			std::cout << ((++rtmp)++)->second << (*rtmp).second << std::endl;


		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
