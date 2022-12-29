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
		NAMESPACE::stack<int>	test;

		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);

		NAMESPACE::stack<int>	test1(test);

		std::cout << test1.empty() << std::endl;
		std::cout << test1.size() << std::endl;
		while (test1.size())
		{
			std::cout << test1.top() << std::endl;
			test1.pop();
		}
		while (test.size())
		{
			std::cout << test.top() << std::endl;
			test.pop();
		}
	
	}
	std::cout << "*******   std::list<int> stack operator=   *******" << std::endl;
	{
		int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::list<int>	lst(tab, tab+10);
		NAMESPACE::stack<int, std::list<int> >	test(lst);

		NAMESPACE::stack<int, std::list<int> >	test1;
		test1.push(42);
		test1.push(21);
		std::cout << test1.size() << std::endl;
		std::cout << test1.top() << std::endl;

		test1 = test;

		std::cout << test1.empty() << std::endl;
		std::cout << test1.size() << std::endl;
		while (test1.size())
		{
			std::cout << test1.top() << std::endl;
			test1.pop();
		}
		while (test.size())
		{
			std::cout << test.top() << std::endl;
			test.pop();
		}
	}
	return (0);
}
