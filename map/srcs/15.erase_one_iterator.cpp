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
		std::cout << "*******   ConstClass<int> map iterator constructor   *******" << std::endl;
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
			{
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >	test(tab.begin(), tab.end(), customCompare<ConstClass<int> >());
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::iterator		it;
				NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > >::const_iterator	other;

				it = test.begin();
				it++;
				other = it;
				it++;
				test.erase(it);
				std::cout << other->first << " : " << other->second << std::endl;
				other++;
				std::cout << other->first << " : " << other->second << std::endl;
				test.erase(--(test.end()));
				test.erase(test.begin());
				other = test.begin();
				for (; other != test.end(); other++)
				{
					std::cout << other->first << " : " << other->second << std::endl;
				}
				while (test.begin() != test.end())
				{
					test.erase(test.begin());
				}
				other = test.begin();
				for (; other != test.end(); other++)
				{
					std::cout << other->first << " : " << other->second << std::endl;
				}
			}
		}
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		std::list<NAMESPACE::pair<ConstClass<int>, ConstClass<int> > > Consttab;
		for (int i = 0; i < 5000; i++)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		for (int i = 10000; i > 5000; i--)
		{
			Consttab.push_back(NAMESPACE::pair<ConstClass<int>, ConstClass<int> >(ConstClass<int>(i), ConstClass<int>(i)));
		}
		timer			timing;

		std::cout << "benchmark" << std::endl;
		for (volatile int loop = 0; loop < 1000 ; loop++)
		{
			NAMESPACE::map<ConstClass<int>, ConstClass<int>, customCompare<ConstClass<int> > > test(Consttab.begin(), Consttab.end(), customCompare<ConstClass<int> >());
			while (test.begin() != test.end())
			{
				std::cout << test.begin()->first << std::endl;
				test.erase(test.begin());
			}
			std::cout << test.size() << std::endl;
		}
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
