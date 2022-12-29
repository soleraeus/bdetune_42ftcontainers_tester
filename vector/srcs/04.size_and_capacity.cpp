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
#include <memory>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   int vector default constructor   *******" << std::endl;
		{
			NAMESPACE::vector<int>	test;
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << test.max_size() << std::endl;
			std::cout << test.empty() << std::endl;
		}
		std::cout << "*******   std::string vector default constructor   *******" << std::endl;
		{
			NAMESPACE::vector<std::string>	test;
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
		}
		std::cout << "*******   ConstClass<int> vector default constructor   *******" << std::endl;
		{
			NAMESPACE::vector<ConstClass<int> >	test;
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
		}
		std::cout << "*******   ConstClass<int> vector range constructor   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<ConstClass<int> >	test(i);
			std::cout << test.size() << std::endl;
			if (test.capacity() < test.size())
				std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
			std::cout << test.max_size() << std::endl;
			NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));
			std::cout << test1.size() << std::endl;
			if (test1.capacity() < test1.size())
				std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
		}
		std::cout << "*******   std::string vector input iterator constructor   *******" << std::endl;
		{
			std::istringstream	str("0 1 2 3 4 8 4");
			NAMESPACE::vector<int>	test((std::istream_iterator<int>(str)), (std::istream_iterator<int>()));
			std::cout << test.size() << std::endl;
			std::cout << test.empty() << std::endl;
			if (test.capacity() < test.size())
				std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
		}

		std::cout << "*******   Testing reserve   *******" << std::endl;
		{
			std::srand(time(NULL));
			unsigned int	ret;
			for (int i = 0; i < 50 ; i++)
			{
				ret = std::rand() % 10000;
				NAMESPACE::vector<int>	test;
				test.reserve(ret);
				if (test.capacity() != ret)
					std::cout << "Wrong capacity" << std::endl;
				std::cout << test.max_size() << std::endl;
				if (test.get_allocator() != std::allocator<int>())
					std::cout << "Wrong allocator returned" << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;
		std::cout << "benchmark" << std::endl;

		for (volatile int loop = 0; loop < 10000; loop++)
		{
			{
				NAMESPACE::vector<int>	test;
				std::cout << test.size() << std::endl;
				std::cout << test.capacity() << std::endl;
				std::cout << test.max_size() << std::endl;
				std::cout << test.empty() << std::endl;
			}
			{
				NAMESPACE::vector<std::string>	test;
				std::cout << test.size() << std::endl;
				std::cout << test.capacity() << std::endl;
			}
			{
				NAMESPACE::vector<ConstClass<int> >	test;
				std::cout << test.size() << std::endl;
				std::cout << test.capacity() << std::endl;
			}
			for (int i = 0; i < 100; i++)
			{
				std::cout << i << std::endl;
				NAMESPACE::vector<ConstClass<int> >	test(i);
				std::cout << test.size() << std::endl;
				if (test.capacity() < test.size())
					std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
				std::cout << test.max_size() << std::endl;
				NAMESPACE::vector<ConstClass<int> >	test1(i, ConstClass<int>(i -1));
				std::cout << test1.size() << std::endl;
				if (test1.capacity() < test1.size())
					std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
			}
			{
				std::istringstream	str("0 1 2 3 4 8 4");
				NAMESPACE::vector<int>	test((std::istream_iterator<int>(str)), (std::istream_iterator<int>()));
				std::cout << test.size() << std::endl;
				std::cout << test.empty() << std::endl;
				if (test.capacity() < test.size())
					std::cout << "Capacity Error: your capacity is lower than size" << std::endl;
			}
			{
				std::srand(time(NULL));
				unsigned int	ret;
				for (int i = 0; i < 50 ; i++)
				{
					ret = std::rand() % 10000;
					NAMESPACE::vector<int>	test;
					test.reserve(ret);
					if (test.capacity() != ret)
						std::cout << "Wrong capacity" << std::endl;
					std::cout << test.max_size() << std::endl;
					if (test.get_allocator() != std::allocator<int>())
						std::cout << "Wrong allocator returned" << std::endl;
				}
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
