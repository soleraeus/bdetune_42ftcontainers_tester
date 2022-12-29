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
		std::cout << "*******   Testing int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>				test;
			NAMESPACE::vector<int>::iterator	start;

			for (int j = 0; j > -200; j--)
			{
				test.push_back(j);
			}
			std::cout << test.size() << std::endl;
			for (start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<std::string>				test;
			NAMESPACE::vector<std::string>::iterator	start;
			std::string									base;

			test.reserve(500);
			start = test.begin();
			base = "a";
			for (int j = 0; j > -200; j--)
			{
				test.push_back((base + std::string("a")));
			}
			std::cout << test.size() << test.capacity() << std::endl;
			for (; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		{
			NAMESPACE::vector<ConstClass<int> >	test;


			for (int j = 0; j > -200; j--)
			{
				test.push_back(ConstClass<int>(j));
			}
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 20000; loop++)
		{
			NAMESPACE::vector<int>			test;

			for (int j = 0; j < loop; j++)
			{
				test.push_back(j);
			}
			std::cout << test.size() << std::endl;
			std::cout << *(test.begin()) << std::endl;
			std::cout << *(test.end() - 1) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}
