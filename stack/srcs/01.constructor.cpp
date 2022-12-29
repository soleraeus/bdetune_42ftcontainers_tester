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
	volatile int x = 0;
	std::cout << "*******   int stack empty constructor   *******" << std::endl;
	for (volatile int i = 0; i < 100; i++)
	{
		NAMESPACE::stack<int>	test;

		std::cout << i << std::endl;
		if (!test.size())
			x += 1;
		else
			x += 2;
	}
	std::cout << "*******   int stack from list<int> constructor   *******" << std::endl;
	for (volatile int i = 0; i < 100; i++)
	{
		int	tab[] = {0, 1, 2, 3, 4, 5};
		std::list<int>	lst(tab, tab+6);
		NAMESPACE::stack<int, std::list<int> >	test(lst);

		std::cout << i << std::endl;
		if (!test.size())
			x += 1;
		else
			x += 2;
	}

	std::cout << "*******   std::string stack empty constructor  *******" << std::endl;
	for (volatile int i = 0; i < 100; i++)
	{
		NAMESPACE::stack<std::string>	test;

		std::cout << i << std::endl;
		if (!test.size())
			x += 1;
		else
			x += 2;
	}
	std::cout << "*******   ConstClass<int> stack empty constructor   *******" << std::endl;
	for (volatile int i = 0; i < 100; i++)
	{
		NAMESPACE::stack<ConstClass<int> >	test;

		std::cout << i << std::endl;
		if (!test.size())
			x += 1;
		else
			x += 2;
	}
	std::cout << x << std::endl;
	return (0);
}
