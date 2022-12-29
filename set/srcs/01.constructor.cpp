#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <iostream>
#include <string>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		volatile int x = 0;
		std::cout << "*******   int set empty constructor   *******" << std::endl;

		for (volatile int i = 0; i < 100; i++)
		{
			NAMESPACE::set<int>	test;

			std::cout << i << std::endl;
			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		std::cout << "*******   std::string set empty constructor  *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			NAMESPACE::set<std::string>	test;

			std::cout << i << std::endl;
			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		std::cout << "*******   ConstClass<int> set empty constructor   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			NAMESPACE::set<ConstClass<int> >	test;

			std::cout << i << std::endl;
			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		std::cerr << x << std::endl;
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		volatile int	x = 0;
		timer			timing;

		std::cout << "benchmark" << std::endl;

		for (volatile int i = 0; i < 10000000; i++)
		{
			NAMESPACE::set<int>	test;

			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		for (volatile int i = 0; i < 10000000; i++)
		{
			NAMESPACE::set<std::string>	test;

			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		for (volatile int i = 0; i < 10000000; i++)
		{
			NAMESPACE::set<ConstClass<int> >	test;

			if (!test.size())
				x += 1;
			else
				x += 2;
		}
		std::cout << x << std::endl;
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
