#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   empty int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test;

			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> vector   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<ConstClass<int> >	test(i);
			NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << start->getValue() << std::endl;
			}
		}
		std::cout << "*******   std::string vector   *******" << std::endl;
		{
			std::istringstream	str("0 1 2 3 4 8 4");
			NAMESPACE::vector<int>	test((std::istream_iterator<int>(str)), (std::istream_iterator<int>()));
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::vector<int>			inttest;
		std::istringstream				str("0 1 2 3 4 8 4");
		NAMESPACE::vector<int>			ittest((std::istream_iterator<int>(str)), (std::istream_iterator<int>()));
		NAMESPACE::vector<ConstClass<int> >	Consttest1(42);
		NAMESPACE::vector<ConstClass<int> >	Consttest2(500, ConstClass<int>(42));

		timer							timing;
		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				for (NAMESPACE::vector<int>::iterator start = inttest.begin(); start != inttest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
			{
				for (NAMESPACE::vector<ConstClass<int> >::iterator start = Consttest1.begin(); start != Consttest1.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				for (NAMESPACE::vector<ConstClass<int> >::iterator start = Consttest2.begin(); start != Consttest2.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				for (NAMESPACE::vector<ConstClass<int> >::iterator start = Consttest2.begin(); start != Consttest2.end(); start++)
				{
					std::cout << start->getValue() << std::endl;
				}
			}
			{
				for (NAMESPACE::vector<int>::iterator start = ittest.begin(); start != ittest.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
