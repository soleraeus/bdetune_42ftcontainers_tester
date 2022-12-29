#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ConstClass.hpp"
#include "timer.hpp"
#include "customCompare.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "*******   int set ranges and bounds   *******" << std::endl;
		{
			int	tab[500];
			for (int i = 0; i < 500; i++)
			{				
				tab[i] = (i % 2) ? -i : i;
			}
			{
				NAMESPACE::set<int>					test(tab, tab+500);
				NAMESPACE::set<int>::iterator			it;
				NAMESPACE::set<int>::const_iterator	it_const;

				for (int i = -10; i < 501; i++)
				{
					if ((it = test.lower_bound(i)) != test.end())
						std::cout << "Lower bound of " << i << " is: " << *it << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in set" << std::endl;

					if ((it_const = test.lower_bound(i)) != test.end())
						std::cout << "Lower bound of " << i << " is: " << *it_const << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in set" << std::endl;
					if ((it = test.upper_bound(i)) != test.end())
						std::cout << "Upper bound of " << i << " is: " << *it << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in set" << std::endl;

					if ((it_const = test.upper_bound(i)) != test.end())
						std::cout << "Upper bound of " << i << " is: " << *it_const << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in set" << std::endl;
					if (test.equal_range(i).first != test.lower_bound(i) || test.equal_range(i).second != test.upper_bound(i))
						std::cout << "Wrong equal range" << std::endl;
				}
			}
		}
		std::cout << "*******   ConstClass<int> set ranges and bounds   *******" << std::endl;
		{
			std::list<ConstClass<int> > tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(ConstClass<int>(i));
			}
			for (int i = 50; i > 25; i--)
			{
				tab.push_back(ConstClass<int>(i));
			}
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(ConstClass<int>(i));
			}
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::iterator			it;
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::const_iterator	it_const;


				for (int i = -10; i < 51; i++)
				{
					if ((it = test.lower_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Lower bound of " << i << " is: " << *it << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in set" << std::endl;

					if ((it_const = test.lower_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Lower bound of " << i << " is: " << *it_const << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in set" << std::endl;
					if ((it = test.upper_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Upper bound of " << i << " is: " << *it << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in set" << std::endl;

					if ((it_const = test.upper_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Upper bound of " << i << " is: " << *it << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in set" << std::endl;
					if (test.equal_range(ConstClass<int>(i)).first != test.lower_bound(ConstClass<int>(i)) || test.equal_range(ConstClass<int>(i)).second != test.upper_bound(ConstClass<int>(i)))
						std::cout << "Wrong equal range" << std::endl;
				}

			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	inttab[5000];
		for (int i = 0; i < 5000; i++)
		{				
			inttab[i] = (i % 2) ? -i : i;
		}
		NAMESPACE::set<int>	test(inttab, inttab+5000);

		std::list<ConstClass<int> > tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(ConstClass<int>(i));
		}
		for (int i = 5000; i > 2500; i--)
		{
			tab.push_back(ConstClass<int>(i));
		}
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >	testConst(tab.begin(), tab.end(), customCompare<ConstClass<int> >());

		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100; loop++)
		{
			for (int i = 0; i < 4999; i++)
			{
				std::cout << *(test.lower_bound(i)) << std::endl;
				std::cout << *(test.upper_bound(i)) << std::endl;
				std::cout << *(test.equal_range(i).first) << std::endl;
			}
			for (int i = 0; i < 4999; i++)
			{
				std::cout << *(testConst.lower_bound(ConstClass<int>(i))) << std::endl;
				std::cout << *(testConst.upper_bound(ConstClass<int>(i))) << std::endl;
				std::cout << *(testConst.equal_range(ConstClass<int>(i)).first) << std::endl;
			}

		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
