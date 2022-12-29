#if ISFT == 1
# define NAMESPACE ft
# include "map.hpp"
#else
# define NAMESPACE std
# include <map>
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
	std::cout << "*******   Int map   *******" << std::endl;
	{
		NAMESPACE::pair<int, int>					tab[10];
		for (int i = 0; i < 10; i++)
		{
			tab[i] = NAMESPACE::pair<int, int>(i, i);
		}
		NAMESPACE::map<int, int>					test(tab, tab+10);

		NAMESPACE::map<int, int>::iterator			it = test.begin();

		it->first = 50;
	}
	return (0);
}
