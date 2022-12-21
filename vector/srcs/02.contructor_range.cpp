#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <iostream>
#include <string>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		volatile int	x = 0;
		std::cout << "*******   int vector range constructor   *******" << std::endl;

		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<int>	test(i);
			NAMESPACE::vector<int>	test1(i, (i - 1));

			std::cout << i << std::endl;
			if (!test.size() || !test1.size())
				x += 1;
			else
				x += 2;
		}
		std::cout << "*******   std::string vector range constructor   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<std::string>	test(i, std::string("Hello"));

			std::cout << i << std::endl;
			if (!test.size())
				x += 1;
			else
				x += 2;

		}
		std::cout << "*******   ConstClass<int> vector range constructor   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<ConstClass<int> >	test(i);
			NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));

			std::cout << i << std::endl;
			if (!test.size() || !test1.size())
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

		for (int i = 0; i < 10000; i++)
		{
			NAMESPACE::vector<int>	test(i);
			NAMESPACE::vector<int>	test1(i, (i - 1));

			if (!test.size() || !test1.size())
				x += 1;
			else
				x += 2;
		}
		for (int i = 0; i < 10000; i++)
		{
			NAMESPACE::vector<std::string>	test(i, std::string("Hello"));

			if (!test.size())
				x += 1;
			else
				x += 2;

		}
		for (int i = 0; i < 10000; i++)
		{
			NAMESPACE::vector<ConstClass<int> >	test(i);
			NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));

			if (!test.size() || !test1.size())
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
