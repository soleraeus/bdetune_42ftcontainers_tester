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
		std::cout << "*******   int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test(25, 10);
			NAMESPACE::vector<int>	test1(test);

			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			for (NAMESPACE::vector<int>::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << *start << std::endl;
			}

		}
		std::cout << "*******   ConstClass<int> vector   *******" << std::endl;
		{
			NAMESPACE::vector<ConstClass<int> >	test(42);
			NAMESPACE::vector<ConstClass<int> >	test1(500, ConstClass<int>(42));
			NAMESPACE::vector<ConstClass<int> >	test2;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test1.begin(); start != test1.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test2 = test1;
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = test2.begin(); start != test2.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			std::cout << (test1.size() == test2.size()) << std::endl;
			std::cout << (test1.capacity() == test2.capacity()) << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::vector<int>			inttest(6666, 13);
		NAMESPACE::vector<ConstClass<int> >	consttest1(6666, ConstClass<int>(42));
		timer							timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 25000; loop++)
		{
			{
				NAMESPACE::vector<int>	test1(inttest);

				std::cout << *(inttest.begin()) << std::endl;
				std::cout << *(test1.begin()) << std::endl;
			}
			{
				NAMESPACE::vector<ConstClass<int> >	test2;
				test2 = consttest1;
				std::cout << *(consttest1.begin()) << std::endl;
				std::cout << *(test2.begin()) << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
