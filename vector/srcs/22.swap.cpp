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
			NAMESPACE::vector<int>				test(10, 55);
			NAMESPACE::vector<int>				cpy(21, 42);
			NAMESPACE::vector<int>				cpy2;
			NAMESPACE::vector<int>::iterator	it;

			test.reserve(50);
			cpy.reserve(100);
			itPrint<NAMESPACE::vector<int>::iterator >(test.begin(), test.end()); 
			itPrint<NAMESPACE::vector<int>::iterator >(cpy.begin(), cpy.end());
			it = test.begin();
			test.swap(cpy);
			itPrint<NAMESPACE::vector<int>::iterator >(test.begin(), test.end()); 
			itPrint<NAMESPACE::vector<int>::iterator >(it, cpy.end()); 
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << cpy.size() << std::endl;
			std::cout << cpy.capacity() << std::endl;
			cpy.swap(cpy2);
			itPrint<NAMESPACE::vector<int>::iterator >(cpy.begin(), cpy.end()); 
			itPrint<NAMESPACE::vector<int>::iterator >(cpy2.begin(), cpy2.end()); 
			std::cout << cpy.size() << std::endl;
			std::cout << cpy.capacity() << std::endl;
			std::cout << cpy2.size() << std::endl;
			std::cout << cpy2.capacity() << std::endl;
		}
		for (volatile int i = 0; i < 100; i++)
		{
			NAMESPACE::vector<ConstClass<int> >			test(10, ConstClass<int>(55));
			NAMESPACE::vector<ConstClass<int> >			cpy(21, ConstClass<int>(42));
			NAMESPACE::vector<ConstClass<int> >			cpy2;
			NAMESPACE::vector<ConstClass<int> >::iterator	it;

			test.reserve(50);
			cpy.reserve(100);
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(test.begin(), test.end()); 
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(cpy.begin(), cpy.end()); 
			it = test.begin();
			NAMESPACE::swap(test, cpy);
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(test.begin(), test.end()); 
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(it, cpy.end()); 
			std::cout << test.size() << std::endl;
			std::cout << test.capacity() << std::endl;
			std::cout << cpy.size() << std::endl;
			std::cout << cpy.capacity() << std::endl;
			NAMESPACE::swap(cpy, cpy2);
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(cpy.begin(), cpy.end()); 
			itPrint<NAMESPACE::vector<ConstClass<int> >::iterator >(cpy2.begin(), cpy2.end()); 
			std::cout << cpy.size() << std::endl;
			std::cout << cpy.capacity() << std::endl;
			std::cout << cpy2.size() << std::endl;
			std::cout << cpy2.capacity() << std::endl;
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::vector<int>	test(200, 42);
		NAMESPACE::vector<int>	test1(1000, 21);

		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 250000; loop++)
		{
			test.swap(test1);
			std::cout << *(test.begin()) << std::endl;
			std::cout << *(test1.begin()) << std::endl;
			NAMESPACE::swap(test, test1);
			std::cout << *(test.begin()) << std::endl;
			std::cout << *(test1.begin()) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}
