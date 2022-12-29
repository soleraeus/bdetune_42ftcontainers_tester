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
		std::cout << "*******   int vector   *******" << std::endl;;
		{
			NAMESPACE::vector<int>	test;
			test.reserve(10);
			test.assign(0, 2);
			std::cout << test.size() << std::endl;
			test.assign(8, 5);
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.assign(6, 2);
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.assign(18, 9);
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   std::string vector   *******" << std::endl;;
		{
			NAMESPACE::vector<std::string>	test;

			test.assign(50, std::string("Hello"));
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.assign(5, std::string("Bye"));
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> vector   *******" << std::endl;;
		{
			NAMESPACE::vector<ConstClass<int> >	test;

			test.reserve(15);
			test.assign(10, ConstClass<int>(10));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.assign(3, ConstClass<int>(2));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.assign(20, ConstClass<int>(5));
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::vector<int>		inttest;
		NAMESPACE::vector<std::string>	stringtest;
		NAMESPACE::vector<ConstClass<int> >	Consttest;
		timer	timing;


		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 4000; loop++)
		{
			{
				inttest.assign(loop, loop);
				std::cout << *(inttest.begin()) << std::endl;
				inttest.assign(1, (loop - 1));
				std::cout << *(inttest.begin()) << std::endl;
				inttest.assign(loop * 3, (loop + 1));
				std::cout << *(inttest.begin()) << std::endl;
				inttest.assign(loop * 9, (loop + 1));
				std::cout << *(inttest.begin()) << std::endl;
			}
			{
				stringtest.assign(loop, std::string("Hi"));
				std::cout << *(stringtest.begin()) << std::endl;
				stringtest.assign(1, std::string("shrink"));
				std::cout << *(stringtest.begin()) << std::endl;
				stringtest.assign(loop * 3, std::string("Not dead yet"));
				std::cout << *(stringtest.begin()) << std::endl;
				stringtest.assign(loop * 9, std::string("I will never die"));
				std::cout << *(stringtest.begin()) << std::endl;
			}
			{
				Consttest.assign(loop, ConstClass<int>(loop));
				std::cout << *(Consttest.begin()) << std::endl;
				Consttest.assign(1, ConstClass<int>(loop - 1));
				std::cout << *(Consttest.begin()) << std::endl;
				Consttest.assign(loop * 3, ConstClass<int>(loop + 1));
				std::cout << *(Consttest.begin()) << std::endl;
				Consttest.assign(loop * 9, ConstClass<int>(loop + 1));
				std::cout << *(Consttest.begin()) << std::endl;
			}
			std::cout << timing.diff() << std::endl;
		}
	}
	else
		return (1);
	return (0);
}
