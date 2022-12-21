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
#include <exception>
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   int map   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>	tab[50];
			for (int i = 0; i < 50; i++)
			{
				tab[i] = NAMESPACE::pair<int, int>(i, -i);
			}
			NAMESPACE::map<int, int>	test(tab, tab+50);

			try
			{
				std::cout << test.at(49) << std::endl;
				std::cout << test.at(0) << std::endl;
				std::cout << test.at(75) << std::endl;
			}
			catch (std::out_of_range const & e)
			{
				std::cout << "Out of range exception raised" << std::endl;
			}
			catch (std::exception const & e)
			{
				std ::cout << "Unhandled exception raised: " << e.what() << std::endl;
			}
			std::cout << test[10] << std::endl;
			std::cout << test[42] << std::endl;
			test.at(5) = -6;
			test.at(11) = 23;
			test[43] = 666;
			test[66] = 42;

			std::cout << test[43] << std::endl;
			std::cout << test[11] << std::endl;
			std::cout << test[5] << std::endl;
			std::cout << test[66] << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>	tab[500];
		for (int i = 0; i < 500; i++)
		{
			tab[i] = NAMESPACE::pair<int, int>(i, -i);
		}
		NAMESPACE::map<int, int>	test(tab, tab+500);

		timer							timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 10000; loop++)
		{
			for (int i = 0; i < 500; i++)
			{
				test[i] = -test[i];
			}	
			for (int i = 0; i < 500; i++)
			{
				std::cout << test.at(i) << std::endl;
			}	
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
