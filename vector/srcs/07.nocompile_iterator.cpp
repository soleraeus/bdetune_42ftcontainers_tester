#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
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
	std::cout << "*******   Testing std::string vector   *******" << std::endl;
	{
		NAMESPACE::vector<std::string>					test(9, std::string("Hello"));
		NAMESPACE::vector<std::string>::iterator		it = test.begin();
		NAMESPACE::vector<std::string>::const_iterator	it_const = test.end();

		it = it_const;
		it_const = test.begin();
		test[0] = std::string("Oupsy");
		*test = std::string("Daisy");
	}
	return (0);
}
