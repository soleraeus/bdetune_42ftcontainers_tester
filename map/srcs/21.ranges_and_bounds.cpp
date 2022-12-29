#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
		std::cout << "*******   int map ranges and bounds   *******" << std::endl;
		{
			NAMESPACE::pair<int, int>	tab[500];
			for (int i = 0; i < 500; i++)
			{				
				tab[i] = (i % 2) ? NAMESPACE::pair<int, int>(-i, i) : NAMESPACE::pair<int, int>(i, i);
			}
			{
				NAMESPACE::map<int, int>					test(tab, tab+500);
				NAMESPACE::map<int, int>::iterator			it;
				NAMESPACE::map<int, int>::const_iterator	it_const;

				for (int i = -10; i < 501; i++)
				{
					if ((it = test.lower_bound(i)) != test.end())
						std::cout << "Lower bound of " << i << " is: " << it->first << " - " << it->second << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in map" << std::endl;

					if ((it_const = test.lower_bound(i)) != test.end())
						std::cout << "Lower bound of " << i << " is: " << it_const->first << " - " << it_const->second << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in map" << std::endl;
					if ((it = test.upper_bound(i)) != test.end())
						std::cout << "Upper bound of " << i << " is: " << it->first << " - " << it->second << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in map" << std::endl;

					if ((it_const = test.upper_bound(i)) != test.end())
						std::cout << "Upper bound of " << i << " is: " << it_const->first << " - " << it_const->second << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in map" << std::endl;
					if (test.equal_range(i).first != test.lower_bound(i) || test.equal_range(i).second != test.upper_bound(i))
						std::cout << "Wrong equal range" << std::endl;
					if (it != test.end())
						it->second += 1;
				}
			}
		}
		std::cout << "*******   ConstClass<int> map ranges and bounds   *******" << std::endl;
		{
			std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			for (int i = 50; i > 25; i--)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			for (int i = 0; i < 25; i++)
			{
				tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
			}
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator			it;
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::const_iterator	it_const;


				for (int i = -10; i < 51; i++)
				{
					if ((it = test.lower_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Lower bound of " << i << " is: " << it->first << " - " << it->second << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in map" << std::endl;

					if ((it_const = test.lower_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Lower bound of " << i << " is: " << it_const->first << " - " << it_const->second << std::endl;
					else
						std::cout << "Lower bound of " << i << " is not in map" << std::endl;
					if ((it = test.upper_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Upper bound of " << i << " is: " << it->first << " - " << it->second << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in map" << std::endl;

					if ((it_const = test.upper_bound(ConstClass<int>(i))) != test.end())
						std::cout << "Upper bound of " << i << " is: " << it_const->first << " - " << it_const->second << std::endl;
					else
						std::cout << "Upper bound of " << i << " is not in map" << std::endl;
					if (test.equal_range(ConstClass<int>(i)).first != test.lower_bound(ConstClass<int>(i)) || test.equal_range(ConstClass<int>(i)).second != test.upper_bound(ConstClass<int>(i)))
						std::cout << "Wrong equal range" << std::endl;
				}

			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		NAMESPACE::pair<int, int>	inttab[5000];
		for (int i = 0; i < 5000; i++)
		{				
			inttab[i] = (i % 2) ? NAMESPACE::pair<int, int>(-i, i) : NAMESPACE::pair<int, int>(i, i);
		}
		NAMESPACE::map<int, int>	test(inttab, inttab+5000);

		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > tab;
		for (int i = 0; i < 2500; i++)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 5000; i > 2500; i--)
		{
			tab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	testConst(tab.begin(), tab.end(), customCompare<ConstClass<int> >());

		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100; loop++)
		{
			for (int i = 0; i < 4999; i++)
			{
				std::cout << test.lower_bound(i)->first << std::endl;
				std::cout << test.upper_bound(i)->first << std::endl;
				std::cout << test.equal_range(i).first->first << std::endl;
			}
			for (int i = 0; i < 4999; i++)
			{
				std::cout << testConst.lower_bound(ConstClass<int>(i))->first << std::endl;
				std::cout << testConst.upper_bound(ConstClass<int>(i))->first << std::endl;
				std::cout << testConst.equal_range(ConstClass<int>(i)).first->first << std::endl;
			}

		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
