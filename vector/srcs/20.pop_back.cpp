#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <list>
#include <iostream>
#include <string>
#include "ConstClass.hpp"
#include "itPrint.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing int vector   *******" << std::endl;;
		for (volatile int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<int>	test;
			test.reserve(100);
			test.assign(99, 5);
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			itPrint<NAMESPACE::vector<int>::iterator>(test.begin(), test.end());
			test.pop_back();
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			while (test.begin() != test.end())
				test.pop_back();
			itPrint<NAMESPACE::vector<int>::iterator>(test.begin(), test.end());
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		}
		std::cout << "*******   Testing std::string vector   *******" << std::endl;;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<std::string>	test;

			test.reserve(50);
			test.assign(50, std::string("Hello"));
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.pop_back();
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
			while (test.begin() != test.end())
				test.pop_back();
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;

		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<ConstClass<int> >	test;

			test.reserve(15);
			test.assign(10, ConstClass<int>(10));
			test.push_back(ConstClass<int>(3));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.pop_back();
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			while (test.begin() != test.end())
				test.pop_back();
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << test.capacity() << std::endl;
			std::cout << test.size() << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<NAMESPACE::vector<int> >	vcts(1000, NAMESPACE::vector<int>(1000, 42));
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (std::list<NAMESPACE::vector<int> >::iterator loop = vcts.begin(); loop != vcts.end(); loop++)
		{
			while (loop->begin() != loop->end())
			{
				std::cout << loop->size() << std::endl;
				loop->pop_back();
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
