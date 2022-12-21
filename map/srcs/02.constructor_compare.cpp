#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
#endif
#include <iostream>
#include <string>
#include "ConstClass.hpp"
#include "timer.hpp"
#include "customCompare.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		volatile int	x = 0;
		std::cout << "*******   ConstClass<int> map with customCompare   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test;
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

		for (int i = 0; i < 1000000; i++)
		{
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test;
			std::cout << i << std::endl;
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
