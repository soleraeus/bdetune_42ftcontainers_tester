#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <list>
#include <exception>
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
		std::cout << "*******   Testing int vector   *******" << std::endl;
		{
			int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			{
				NAMESPACE::vector<int>	test;
				std::list<int>			filler(1000, 1);

				test.insert(test.begin(), tab, tab+10);
				test.insert(test.end(), tab+3, tab+4);
				test.insert(test.begin(), tab+10, tab+10);
				test.insert((test.begin() + 3), tab+1, tab+4);
				for (NAMESPACE::vector<int>::iterator start = test.begin(); start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				test.insert(test.begin(), filler.begin(), filler.end());
				test.insert(test.begin(), filler.begin(), filler.end());
				test.insert(test.end(), filler.begin(), filler.end());
				test.insert(test.begin(), filler.begin(), filler.end());
				test.insert(test.begin(), filler.begin(), filler.end());
				std::cout << *(test.begin()) << std::endl;
			}
		}
		std::cout << "*******   Testing Input iterator   *******" << std::endl;
		{
			{
				double	tab[]= {3.2, 5.5};
				std::istringstream	str("0.0 0.1 1.2 5.3 6.4 8.9 10.4");
				NAMESPACE::vector<double>	test;
				
				test.insert(test.begin(), tab, tab+2);
				test.insert(test.begin(), (std::istream_iterator<double>(str)), (std::istream_iterator<double>()));
				for (NAMESPACE::vector<double>::iterator start = test.begin(); start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
			}
			{
				double	tab[]= {3.2, 5.5};
				std::istringstream	str("0.0 0.1 1.2 5.3 6.4 8.9 10.4");
				NAMESPACE::vector<double>			test;
				NAMESPACE::vector<double>::iterator	start;
				
				test.reserve(100);
				test.insert(test.begin(), tab, tab+2);
				test.insert(test.begin(), (std::istream_iterator<double>(str)), (std::istream_iterator<double>()));
				start = test.begin();
				test.insert(test.end(), (std::istream_iterator<double>(str)), (std::istream_iterator<double>()));
				for (; start != test.end(); start++)
				{
					std::cout << *start << std::endl;
				}
				std::cout << "Capacity: " << test.capacity() << std::endl;
			}

		}
		std::cout << "*******   Testing ConstClass<int> vector   *******" << std::endl;
		{
			ConstClass<int>	tab[] = {ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10)};
			ConstClass<int>	tab2[] = {ConstClass<int>(666), ConstClass<int>(42)};
			{
				NAMESPACE::vector<ConstClass<int> >	test;


				test.reserve(50);
				test.insert(test.begin(), tab, tab+3);
				test.insert(test.begin(), tab2, tab2+2);
				test.insert(test.end(), tab2, tab2+1);
				for (NAMESPACE::vector<ConstClass<int> >::iterator it = test.begin(); it != test.end(); it++)
				{
					std::cout << *it << std::endl;
				}
				test.insert((test.begin() + 3), tab, tab);
				test.insert((test.begin() + 5), tab2, tab2+2);
				for (NAMESPACE::vector<ConstClass<int> >::iterator it = test.begin(); it != test.end(); it++)
				{
					std::cout << *it << std::endl;
				}
				std::cout << "Capacity: " << test.capacity() << std::endl;
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	tab[500];
		for (int i = 0; i < 500; i++)
		{
			tab[i] = i;
		}
		std::list<int>			filler(1000, 1);
		timer	timing;

		std::cout << "benchmark" << std::endl;
		for (int loop = 1; loop < 20000; loop++)
		{
			{
				NAMESPACE::vector<int>	test;

				test.insert(test.begin(), tab, tab+10);
				test.insert(test.end(), tab+3, tab+4);
				test.insert(test.begin(), tab+10, tab+10);
				test.insert((test.begin() + 3), tab+1, tab+480);
				test.insert(test.end(), tab, tab+500);
				test.insert(test.begin(), tab, tab+500);
				test.insert((test.end() - 4), tab, tab+500);
				test.insert((test.begin() + 1000), tab, tab+500);

				std::cout << *(test.begin()) << std::endl;
			}
			{
				std::istringstream	str("0.75 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4 0.0 0.1 1.2 5.3 6.4 8.9 10.4");
				double	tabdouble[]= {3.2, 5.5};
				NAMESPACE::vector<double>	test;
				
				test.insert(test.begin(), tabdouble, tabdouble+2);
				test.insert(test.begin(), (std::istream_iterator<double>(str)), (std::istream_iterator<double>()));

				std::cout << *(test.begin()) << std::endl;
			}

		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);

	return (0);
}

