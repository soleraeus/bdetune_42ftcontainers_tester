#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <exception>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <memory>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing emtpy int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test;
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.empty() << std::endl;
			
			test.clear();

			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<ConstClass<int> >	test(i);
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			test.clear();
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   Testing int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test(10, 1);
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			for (NAMESPACE::vector<int>::const_iterator start = test.begin(); start != test.end() ; start++)
			{
				std::cout << *start << std::endl;
			}
			test.clear();
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			for (NAMESPACE::vector<int>::const_iterator start = test.begin(); start != test.end() ; start++)
			{
				std::cout << *start << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100000; loop++)
		{
			{
				NAMESPACE::vector<int>	test;
				std::cout << test.size() << std::endl;
				std::cout << test.capacity() << std::endl;
				std::cout << test.empty() << std::endl;
				
				test.clear();

				std::cout << test.size() << std::endl;
				std::cout << test.capacity() << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::vector<ConstClass<int> >	test(200);
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
				test.clear();
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::vector<int>	test(100, 1);
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
				test.clear();
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
