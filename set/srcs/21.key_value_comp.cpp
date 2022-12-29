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
		std::cout << "*******   int set comps   *******" << std::endl;
		{
			{
				NAMESPACE::set<int>					test;
				std::less<int>								key_cmp = test.key_comp();
				NAMESPACE::set<int>::value_compare		value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(2, 1) << std::endl;

				std::cout << std::boolalpha << value_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << value_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << value_cmp(2, 1) << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> set ranges and bounds   *******" << std::endl;
		{
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >					test;
				customCompare<ConstClass<int> >															key_cmp = test.key_comp();
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::value_compare	value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;

				std::cout << std::boolalpha << value_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;


			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 100000; loop++)
		{
			{
				NAMESPACE::set<int>					test;
				std::less<int>								key_cmp = test.key_comp();
				NAMESPACE::set<int>::value_compare		value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(2, 1) << std::endl;

				std::cout << std::boolalpha << value_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << value_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << value_cmp(2, 1) << std::endl;
			}
			{
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >					test;
				customCompare<ConstClass<int> >															key_cmp = test.key_comp();
				NAMESPACE::set<ConstClass<int>, customCompare<ConstClass<int> > >::value_compare	value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;

				std::cout << std::boolalpha << value_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;


			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
