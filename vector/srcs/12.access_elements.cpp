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
		std::cout << "*******   Testing int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test(25, 10);
			int*					data;

			std::cout << test.front() << std::endl;
			std::cout << test.back() << std::endl;
			std::cout << test[0] << std::endl;
			data = test.data();
			for (int i = 0; i < 25; i++)
			{
				std::cout << data[i] << std::endl;
			}
			try
			{
				std::cout << test.at(1) << std::endl;
				std::cout << test.at(50) << std::endl;
			}
			catch (std::out_of_range const & e)
			{
				std::cout << "Exception caught" << std::endl;
			}
			test[2] = 42;
			test.at(21) = 56;
			for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
			{
				std::cout << *it << std::endl;
			}
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		for (int i = 1; i < 100; i++)
		{
			NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));
			std::cout << (test1[0].getValue() == test1.front().getValue() ? "true" : "false") << std::endl;
			std::cout << (test1[i - 1].getValue() == test1.back().getValue() ? "true" : "false") << std::endl;
			std::cout << (test1.data() == &(*(test1.begin())) ? "true" : "false") << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::vector<int>		test(25, 10);
		int*				data;
		NAMESPACE::vector<ConstClass<int> >	test1(100, ConstClass<int>(99));
		test1.push_back(ConstClass<int>(42));
		
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 1; loop < 40000; loop++)
		{

			std::cout << test.front() << std::endl;
			std::cout << test.back() << std::endl;
			std::cout << test[0] << std::endl;
			data = test.data();
			for (int i = 0; i < 25; i++)
			{
				std::cout << data[i] << std::endl;
			}
			try
			{
				std::cout << test.at(1) << std::endl;
				std::cout << test.at(50) << std::endl;
			}
			catch (std::out_of_range const & e)
			{
				std::cout << "Exception caught" << std::endl;
			}
			test[2] = 42;
			test.at(21) = 56;
			for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
			{
				std::cout << *it << std::endl;
			}
			std::cout << (test1[0].getValue() == test1.front().getValue() ? "true" : "false") << std::endl;
			std::cout << (test1[100].getValue() == test1.back().getValue() ? "true" : "false") << std::endl;
			std::cout << (test1.data() == &(*(test1.begin())) ? "true" : "false") << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
