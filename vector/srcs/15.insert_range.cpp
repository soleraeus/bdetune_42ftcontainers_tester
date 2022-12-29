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
			NAMESPACE::vector<int>	test;

			test.insert(test.begin(), 5, 42);
			test.insert(test.begin(), 10, 24);
			test.insert(test.end(), 2, 420);
			test.insert((test.begin() + 1), 1, 666);
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.insert((test.begin() + 1), 1000, 666);
			test.insert((test.begin() + 1), 1000, 666);
			test.insert((test.begin() + 1), 1000, 666);
			test.insert((test.begin() + 1), 1000, 666);
			test.insert((test.begin() + 1), 1000, 666);
			for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   Testing std::string vector   *******" << std::endl;
		{
			NAMESPACE::vector<std::string>	test;

			test.insert(test.end(), 5, std::string("Bye"));
			test.insert(test.end(), 7, std::string("Re-bye"));
			test.insert(test.begin(),1 , std::string("Hello"));
			test.insert((test.begin() + 1), 2, std::string("How are you?"));
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.insert(test.end(), 1000, std::string("Re-bye"));
			test.insert(test.end(), 1000, std::string("Re-bye"));
			test.insert(test.end(), 1000, std::string("Re-bye"));
			test.insert(test.end(), 1000, std::string("Re-bye"));
			test.insert(test.end(), 1000, std::string("Re-bye"));
			for (NAMESPACE::vector<std::string>::iterator start = test.begin(); start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		{
			NAMESPACE::vector<ConstClass<int> >			test;
			NAMESPACE::vector<ConstClass<int> >::iterator	it;

			test.reserve(50);
			test.insert(test.begin(), 3, ConstClass<int>(42));
			test.insert(test.begin(), 2, ConstClass<int>(24));
			it = test.begin();
			test.insert(test.end(), 4, ConstClass<int>(420));
			test.insert((test.begin() + 1), 13, ConstClass<int>(666));
			for (; it != test.end(); it++)
			{
				std::cout << *it << std::endl;
			}
			test.insert((test.begin()), 50, ConstClass<int>(888));
			for (it = test.begin(); it != test.end(); it++)
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
				NAMESPACE::vector<std::string>	test;

				test.insert(test.end(), 5, std::string("Bye"));
				test.insert(test.end(), 7, std::string("Re-bye"));
				test.insert(test.begin(),1 , std::string("Hello"));
				test.insert((test.begin() + 1), 2, std::string("How are you?"));

				std::cout << *(test.begin()) << std::endl;

				test.insert(test.end(), 1000, std::string("Re-bye"));
				test.insert(test.end(), 1000, std::string("Re-bye"));
				test.insert(test.end(), 1000, std::string("Re-bye"));
				test.insert(test.end(), 1000, std::string("Re-bye"));
				test.insert(test.end(), 1000, std::string("Re-bye"));
				test.insert(test.begin(), 2000, std::string("Re-bye"));
				test.insert(test.begin(), 2000, std::string("Re-bye"));
				test.insert(test.begin(), 2000, std::string("Re-bye"));
				test.insert(test.begin(), 2000, std::string("Re-bye"));

				std::cout << *(test.begin()) << std::endl;
			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}
