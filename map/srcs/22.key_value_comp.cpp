#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
		std::cout << "*******   int map comps   *******" << std::endl;
		{
			{
				NAMESPACE::map<int, int>					test;
				std::less<int>								key_cmp = test.key_comp();
				NAMESPACE::map<int, int>::value_compare		value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(2, 1) << std::endl;

				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(0, 1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(0, 2)) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(1, 1)) << std::endl;
			}
		}
		std::cout << "*******   ConstClass<int> map ranges and bounds   *******" << std::endl;
		{
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >					test;
				customCompare<ConstClass<int> >															key_cmp = test.key_comp();
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::value_compare	value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;

				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1))) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(2))) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(1), ConstClass<int>(1))) << std::endl;

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
				NAMESPACE::map<int, int>					test;
				std::less<int>								key_cmp = test.key_comp();
				NAMESPACE::map<int, int>::value_compare		value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(0, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(1, 1) << std::endl;
				std::cout << std::boolalpha << key_cmp(2, 1) << std::endl;

				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(0, 1)) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(0, 2)) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<int, int>(0, 1), NAMESPACE::pair<int, int>(1, 1)) << std::endl;
			}
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >					test;
				customCompare<ConstClass<int> >															key_cmp = test.key_comp();
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::value_compare	value_cmp = test.value_comp();

				std::cout << std::boolalpha << key_cmp(ConstClass<int>(0), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(1), ConstClass<int>(1)) << std::endl;
				std::cout << std::boolalpha << key_cmp(ConstClass<int>(2), ConstClass<int>(1)) << std::endl;

				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1))) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(2))) << std::endl;
				std::cout << std::boolalpha << value_cmp(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(0), ConstClass<int>(1)), NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(1), ConstClass<int>(1))) << std::endl;

			}
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
