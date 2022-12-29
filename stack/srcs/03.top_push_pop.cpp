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
	std::cout << "*******   Testing int stack   *******" << std::endl;
	{
		NAMESPACE::stack<int>	test;

		test.push(1);
		test.push(42);
		test.push(23);
		test.push(-23);
		test.push(9);
		test.push(5);
		test.push(8);
		test.push(95);
		test.push(1337);
		test.push(21);
		test.push(0);

		std::cout << test.top() << std::endl;
		test.top() = -42;
		std::cout << test.top() << std::endl;
		test.pop();
		std::cout << test.top() << std::endl;
		while (test.size())
		{
			std::cout << test.top() << std::endl;
			test.pop();
		}
	}
	std::cout << "*******   std::list<int> int stack   *******" << std::endl;
	{
		int	tab[] = {0, 1, 2, 3, 4, 5};
		std::list<int>	lst(tab, tab+6);
		NAMESPACE::stack<int, std::list<int> >	test(lst);

		std::cout << test.top() << std::endl;
		test.top() = -42;
		std::cout << test.top() << std::endl;
		test.pop();
		std::cout << test.top() << std::endl;
		while (test.size())
		{
			std::cout << test.top() << std::endl;
			test.pop();
		}
	}

	return (0);
}
