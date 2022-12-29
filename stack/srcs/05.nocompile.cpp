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

int	main(void)
{
	std::cout << "*******   int stack   *******" << std::endl;
	{
		NAMESPACE::stack<int>			test;
		NAMESPACE::stack<int>::iterator start;

		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);

		(void) start;
	}
	return (0);
}
