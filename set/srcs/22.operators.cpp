#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <list>
#include <iostream>
#include <ios>
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
		std::cout << "*******   int set operators   *******" << std::endl;
		{
			int	tab[500];
			for (int i = 0; i < 500; i++)
			{				
				tab[i] = (i % 2) ? -i : i;
			}
			{
				NAMESPACE::set<int>					test(tab, tab+500);
				NAMESPACE::set<int>					test2(tab+3, tab+500);
				NAMESPACE::set<int>					test3(tab, tab+500);
				NAMESPACE::set<int>					test4(tab, tab+499);
				NAMESPACE::set<int>					test5;

				std::cout << std::boolalpha << (test == test2) << " " << (test != test2) << " " << (test < test2) << " " << (test <= test2) << " " << (test > test2) << " " << (test >= test2) << std::endl;

				std::cout << std::boolalpha << (test == test3) << " " << (test != test3) << " " << (test < test3) << " " << (test <= test3) << " " << (test > test3) << " " << (test >= test3) << std::endl;

				std::cout << std::boolalpha << (test == test4) << " " << (test != test4) << " " << (test < test4) << " " << (test <= test4) << " " << (test > test4) << " " << (test >= test4) << std::endl;

				std::cout << std::boolalpha << (test == test5) << " " << (test != test5) << " " << (test < test5) << " " << (test <= test5) << " " << (test > test5) << " " << (test >= test5) << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> set operators   *******" << std::endl;
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
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		test(tab.begin(), tab.end());
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		test2(++tab.begin(), tab.end());
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		test3(++tab.begin(), --tab.end());
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		test4(tab.begin(), --tab.end());
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		test5;

				std::cout << std::boolalpha << (test == test2) << " " << (test != test2) << " " << (test < test2) << " " << (test <= test2) << " " << (test > test2) << " " << (test >= test2) << std::endl;

				std::cout << std::boolalpha << (test == test3) << " " << (test != test3) << " " << (test < test3) << " " << (test <= test3) << " " << (test > test3) << " " << (test >= test3) << std::endl;

				std::cout << std::boolalpha << (test == test4) << " " << (test != test4) << " " << (test < test4) << " " << (test <= test4) << " " << (test > test4) << " " << (test >= test4) << std::endl;

				std::cout << std::boolalpha << (test == test5) << " " << (test != test5) << " " << (test < test5) << " " << (test <= test5) << " " << (test > test5) << " " << (test >= test5) << std::endl;

			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		int	tab[500];
		for (int i = 0; i < 500; i++)
		{				
			tab[i] = (i % 2) ? -i : i;
		}
		NAMESPACE::set<int>					test(tab, tab+500);
		NAMESPACE::set<int>					test2(tab+3, tab+500);
		NAMESPACE::set<int>					test3(tab, tab+500);
		NAMESPACE::set<int>					test4(tab, tab+499);
		NAMESPACE::set<int>					test5;

		std::list<ConstClass<int> > tabConst;
		for (int i = 0; i < 25; i++)
		{
			tabConst.push_back(ConstClass<int>(i));
		}
		for (int i = 50; i > 25; i--)
		{
			tabConst.push_back(ConstClass<int>(i));
		}
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		testConst(tabConst.begin(), tabConst.end());
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		testConst2(++tabConst.begin(), tabConst.end());
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		testConst3(++tabConst.begin(), --tabConst.end());
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		testConst4(tabConst.begin(), --tabConst.end());
		NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >		testConst5;




		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 11111; loop++)
		{
			// int, int
			std::cout << std::boolalpha << (test == test2) << " " << (test != test2) << " " << (test < test2) << " " << (test <= test2) << " " << (test > test2) << " " << (test >= test2) << std::endl;

			std::cout << std::boolalpha << (test == test3) << " " << (test != test3) << " " << (test < test3) << " " << (test <= test3) << " " << (test > test3) << " " << (test >= test3) << std::endl;

			std::cout << std::boolalpha << (test == test4) << " " << (test != test4) << " " << (test < test4) << " " << (test <= test4) << " " << (test > test4) << " " << (test >= test4) << std::endl;

			std::cout << std::boolalpha << (test == test5) << " " << (test != test5) << " " << (test < test5) << " " << (test <= test5) << " " << (test > test5) << " " << (test >= test5) << std::endl;

			//ConstClass<int>, ConstClass<int>
			std::cout << std::boolalpha << (testConst == testConst2) << " " << (testConst != testConst2) << " " << (testConst < testConst2) << " " << (testConst <= testConst2) << " " << (testConst > testConst2) << " " << (testConst >= testConst2) << std::endl;

			std::cout << std::boolalpha << (testConst == testConst3) << " " << (testConst != testConst3) << " " << (testConst < testConst3) << " " << (testConst <= testConst3) << " " << (testConst > testConst3) << " " << (testConst >= testConst3) << std::endl;

			std::cout << std::boolalpha << (testConst == testConst4) << " " << (testConst != testConst4) << " " << (testConst < testConst4) << " " << (testConst <= testConst4) << " " << (testConst > testConst4) << " " << (testConst >= testConst4) << std::endl;

			std::cout << std::boolalpha << (testConst == testConst5) << " " << (testConst != testConst5) << " " << (testConst < testConst5) << " " << (testConst <= testConst5) << " " << (testConst > testConst5) << " " << (testConst >= testConst5) << std::endl;


		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
