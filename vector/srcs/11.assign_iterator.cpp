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
			int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			for (volatile int i = 0; i < 100; i++)
			{
				std::cout << i << std::endl;
				NAMESPACE::vector<int>	test;
				
				test.reserve(12);
				test.assign(tab+10, tab+10);
				test.assign(tab, tab+10);
				std::cout << test.capacity() << std::endl;
				std::cout << test.size() << std::endl;
				for (NAMESPACE::vector<int>::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				test.assign(tab+3, tab+5);
				std::cout << test.capacity() << std::endl;
				std::cout << test.size() << std::endl;
				for (NAMESPACE::vector<int>::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				test.assign(tab+9, tab+9);
				std::cout << test.capacity() << std::endl;
				std::cout << test.size() << std::endl;
				for (NAMESPACE::vector<int>::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
		}
		std::cout << "*******   Testing input iterator vector   *******" << std::endl;
		{

			for (volatile int i = 0; i < 100; i++)
			{
				std::istringstream	str("0.42 0.1 1.2 5.3 6.4 8.9 10.4");
				std::cout << i << std::endl;
				NAMESPACE::vector<double>	test;
				
				test.assign((std::istream_iterator<double>(str)), (std::istream_iterator<double>()));
				std::cout << test.size() << std::endl;
				if (test.capacity() < test.size())
					std::cout << "Wrong capacity after input iterator" << std::endl;
				for (NAMESPACE::vector<double>::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		{
			ConstClass<int>	tab[] = {ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10)};
			ConstClass<int>	tab2[] = {ConstClass<int>(52), ConstClass<int>(21), ConstClass<int>(8)};
			std::list<ConstClass<int> >	filler(tab, tab+3);
			for (volatile int i = 0; i < 100; i++)
			{
				std::cout << i << std::endl;
				NAMESPACE::vector<ConstClass<int> >	test;
				test.assign(filler.begin(), filler.end());
				std::cout << test.size() << std::endl;
				for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				test.assign(tab2, tab2+2);
				std::cout << test.size() << std::endl;
				for (NAMESPACE::vector<ConstClass<int> >::iterator start = test.begin();  start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{

		int	inttab[1000];
		for (int i = 0; i < 1000; i++)
		{
			inttab[i] = i;
		}
		std::istringstream	str("0.25 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4");
		std::list<ConstClass<int> >	Constlist;
		for (int i = 1; i < 1000; i++)
		{
			Constlist.push_back(ConstClass<int>(i));
		}
		NAMESPACE::vector<int>		intvct;
		NAMESPACE::vector<double>	doublevct;
		NAMESPACE::vector<ConstClass<int> >	Constvct;

		timer	timing;
		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 200000; loop++)
		{
			intvct.assign(inttab, inttab+1000);
			std::cout << *(intvct.begin()) << std::endl;
			doublevct.assign((std::istream_iterator<double>(str)), (std::istream_iterator<double>()));
			std::cout << *(doublevct.begin()) << std::endl;
			Constvct.assign(Constlist.begin(), Constlist.end());
			std::cout << *(Constvct.begin()) << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
