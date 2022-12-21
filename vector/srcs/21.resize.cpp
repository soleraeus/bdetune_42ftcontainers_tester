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
#include "itPrint.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   Testing int vector   *******" << std::endl;
		{
			NAMESPACE::vector<int>				test;
			NAMESPACE::vector<int>::iterator	it;
			NAMESPACE::vector<int>::size_type	capacity;

			test.resize(21);
			test.resize(21);
			std::cout << test.size() << std::endl;
			itPrint<NAMESPACE::vector<int>::iterator >(test.begin(), test.end()); 
			test.resize(2000, 42);
			it = test.begin();
			capacity = test.capacity();
			test.resize(1, 6);
			test.resize(500);
			itPrint<NAMESPACE::vector<int>::iterator >(it, test.end()); 
			std::cout << test.size() << std::endl;
			std::cout << (capacity == test.capacity() ? "true" : " false") << std::endl;
		}
		std::cout << "*******   Testing std::string vector   *******" << std::endl;;
		{
			NAMESPACE::vector<std::string>				test;
			NAMESPACE::vector<std::string>::iterator	it;
			NAMESPACE::vector<std::string>::size_type	capacity;

			test.resize(21);
			test.resize(21);
			std::cout << test.size() << std::endl;
			itPrint<NAMESPACE::vector<std::string>::iterator >(test.begin(), test.end()); 
			test.resize(2000, std::string("Hi"));
			it = test.begin();
			capacity = test.capacity();
			test.resize(1, std::string("Bye"));
			itPrint<NAMESPACE::vector<std::string>::iterator >(test.begin(), test.end()); 
			test.resize(500);
			itPrint<NAMESPACE::vector<std::string>::iterator >(it, test.end()); 
			std::cout << test.size() << std::endl;
			std::cout << (capacity == test.capacity() ? "true" : " false") << std::endl;
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;;
		{
			NAMESPACE::vector<ConstClass<int> >	test;

			test.reserve(50);
			test.resize(10, ConstClass<int>(10));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(test.begin(), test.end()); 
			test.resize(1, ConstClass<int>(2));
			test.resize(33, ConstClass<int>(42));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(test.begin(), test.end()); 
			test.resize(0, ConstClass<int>(21));
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(test.begin(), test.end()); 
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 20000; loop++)
		{
			NAMESPACE::vector<int>			test;

			test.resize(21);
			std::cout << test.size() << std::endl;
			test.resize(21);
			std::cout << test.size() << std::endl;
			test.resize(2000, 42);
			test.resize(1, 6);
			test.resize(500);
			std::cout << test.size() << std::endl;
			test.resize(0);
			std::cout << test.size() << std::endl;
			test.resize(loop);
			std::cout << test.size() << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}
