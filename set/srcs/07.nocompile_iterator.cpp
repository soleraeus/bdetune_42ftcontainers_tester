#if ISFT == 1
# define NAMESPACE ft
# include "set.hpp"
#else
# define NAMESPACE std
# include <set>
#endif
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ConstClass.hpp"

int	main(void)
{
	std::cout << "*******   Int set   *******" << std::endl;
	{
		int					tab[10];
		for (int i = 0; i < 10; i++)
		{
			tab[i] = i;
		}
		NAMESPACE::set<int>					test(tab, tab+10);
		NAMESPACE::set<int>::iterator		it = test.begin();

		*it = 50;
		std::cout << *it << std::endl;
	}
	return (0);
}
