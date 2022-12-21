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
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<int>	test;

			test.insert(test.begin(), 42);
			test.insert(test.begin(), 24);
			test.insert(test.end(), 420);
			test.insert((test.begin() + 1), 666);
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   Testing std::string vector   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<std::string>	test;

			test.insert(test.end(), std::string("Bye"));
			test.insert(test.end(), std::string("Re-bye"));
			test.insert(test.begin(), std::string("Hello"));
			test.insert((test.begin() + 1), std::string("How are you?"));
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}

		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		for (volatile int i = 0; i < 100; i++)
		{
			std::cout << i << std::endl;
			NAMESPACE::vector<ConstClass<int> >			test;
			NAMESPACE::vector<ConstClass<int> >::iterator	it;

			test.reserve(20);
			test.insert(test.begin(), ConstClass<int>(42));
			test.insert(test.begin(), ConstClass<int>(24));
			it = test.begin();
			test.insert(test.end(), ConstClass<int>(420));
			test.insert((test.begin() + 1), ConstClass<int>(666));
			for (; it != test.end(); it++)
			{
				std::cout << *it << std::endl;
			}

		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 2000; loop++)
		{
			{
				NAMESPACE::vector<int>	test;

				test.insert(test.begin(), 42);
				test.insert(test.begin(), 24);
				test.insert(test.end(), 420);
				test.insert((test.begin() + 1), 666);
				for (int j = 0; j < loop/4; j++)
				{
					test.insert(test.begin(), j);
				}
				for (int j = 0; j < loop/4; j++)
				{
					test.insert(test.end(), j);
				}

				for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
			{
				NAMESPACE::vector<ConstClass<int> >			test;

				test.insert(test.begin(), ConstClass<int>(42));
				test.insert(test.begin(), ConstClass<int>(24));
				test.insert(test.end(), ConstClass<int>(420));
				test.insert((test.begin() + 1), ConstClass<int>(666));
				for (int j = 0; j < loop/4; j++)
				{
					test.insert(test.begin(), ConstClass<int>(j));
				}
				for (int j = 0; j < loop/4; j++)
				{
					test.insert(test.end(), ConstClass<int>(j));
				}

				for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin(); start != test.end(); start++)
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
