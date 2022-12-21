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
		std::cout << "*******   Testing int vector   *******" << std::endl;;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<int>				test(100, i);
			NAMESPACE::vector<int>::size_type	capacity;
			NAMESPACE::vector<int>::iterator	it = test.begin();

			capacity = test.capacity();
			std::cout << test.size() << std::endl;
			*(test.begin()) = -1;
			*(test.end() - 1) = 666;
			for (NAMESPACE::vector<int>::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.begin() + 1), (test.begin() + 10));
			std::cout << test.size() << std::endl;
			test.erase((test.end() - 1), test.end());
			test.erase((test.begin(), test.begin()));
			for (NAMESPACE::vector<int>::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.end() + 1), (test.end() + 1));
			std::cout << test.size() << std::endl;
			test.erase(test.begin(), test.end());
			std::cout << test.size() << std::endl;
			if (capacity != test.capacity())
				std::cout << "Wrong capacity detected" << std::endl;
		}
		std::cout << "*******   Testing std::string vector   *******" << std::endl;;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<std::string>	test(100, std::string("Hello"));
			NAMESPACE::vector<std::string>::size_type	capacity;
			NAMESPACE::vector<std::string>::iterator	it = test.begin();

			capacity = test.capacity();
			std::cout << test.size() << std::endl;
			*(test.begin()) = std::string("Youhou");
			*(test.end() - 1) = std::string("Bye");
			for (NAMESPACE::vector<std::string>::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.begin() + 1), (test.begin() + 10));
			std::cout << test.size() << std::endl;
			test.erase((test.end() - 1), test.end());
			test.erase((test.begin(), test.begin()));
			for (NAMESPACE::vector<std::string>::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.end() + 1), (test.end() + 1));
			std::cout << test.size() << std::endl;
			test.erase(test.begin(), test.end());
			std::cout << test.size() << std::endl;
			if (capacity != test.capacity())
				std::cout << "Wrong capacity detected" << std::endl;

		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<ConstClass<int> >	test(100, ConstClass<int>(i -1));
			NAMESPACE::vector<ConstClass<int> >::size_type	capacity;
			NAMESPACE::vector<ConstClass<int> >::iterator	it = test.begin();

			capacity = test.capacity();
			std::cout << test.size() << std::endl;
			*(test.begin()) = ConstClass<int>(-42);
			*(test.end() - 1) = ConstClass<int>(666);
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.begin() + 1), (test.begin() + 10));
			std::cout << test.size() << std::endl;
			test.erase((test.end() - 1), test.end());
			test.erase((test.begin(), test.begin()));
			for (NAMESPACE::vector<ConstClass<int> >::iterator start = it; start != test.end(); start++)
			{
				std::cout << *start << std::endl;
			}
			test.erase((test.end() + 1), (test.end() + 1));
			std::cout << test.size() << std::endl;
			test.erase(test.begin(), test.end());
			std::cout << test.size() << std::endl;
			if (capacity != test.capacity())
				std::cout << "Wrong capacity detected" << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 100000; loop++)
		{
			NAMESPACE::vector<int>			test(1000, 42);

			std::cout << test.size() << std::endl;
			*(test.begin()) = -1;
			*(test.end() - 1) = 666;

			std::cout << *(test.begin()) << std::endl;

			test.erase((test.begin() + 1));
			std::cout << test.size() << std::endl;
			test.erase((test.end() - 1));
			test.erase((test.begin() + 10));

			std::cout << *(test.begin()) << std::endl;
			std::cout << test.size() << std::endl;

			test.erase(test.begin(), test.end());
			std::cout << test.size() << std::endl;

		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}
