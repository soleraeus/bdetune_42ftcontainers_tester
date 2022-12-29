#if ISFT == 1
# define NAMESPACE ft
# include "stack.hpp"
#else
# define NAMESPACE std
# include <stack>
#endif
#include <list>
#include <iostream>
#include <string>
#include "ConstClass.hpp"

int	main(void)
{
	std::cout << "*******   int stack default constructor   *******" << std::endl;
	{
		NAMESPACE::stack<int>	test;
		std::cout << test.size() << std::endl;
		std::cout << test.empty() << std::endl;
	}
	std::cout << "*******   std::string stack default constructor   *******" << std::endl;
	{
		NAMESPACE::stack<std::string>	test;
		std::cout << test.size() << std::endl;
		std::cout << test.empty() << std::endl;
	}
	std::cout << "*******   ConstClass<int> stack default constructor   *******" << std::endl;
	{
		NAMESPACE::stack<ConstClass<int> >	test;
		std::cout << test.size() << std::endl;
		std::cout << test.empty() << std::endl;
	}
	std::cout << "*******   std::list<int> stack range constructor   *******" << std::endl;
	{
		int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::list<int>	lst(tab, tab+10);
		NAMESPACE::stack<int, std::list<int> >	test(lst);

		std::cout << test.empty() << std::endl;
		std::cout << test.size() << std::endl;
	}
	return (0);
}
