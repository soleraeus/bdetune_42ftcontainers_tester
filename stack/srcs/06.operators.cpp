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
		int						tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::list<int>			lst(tab, tab+10);
		NAMESPACE::stack<int, std::list<int> >	test(lst);
		NAMESPACE::stack<int, std::list<int> >	test2(test);
		lst.pop_back();
		NAMESPACE::stack<int, std::list<int> >	test3(lst);
		NAMESPACE::stack<int, std::list<int> >	test4;
		lst.push_back(42);
		NAMESPACE::stack<int, std::list<int> >	test5(lst);

		std::cout << (test == test2) << " " << (test != test2) << " " << (test < test2) << " " << (test <= test2) << " " << (test > test2) << " " << (test >= test2) << std::endl;

		std::cout << (test == test3) << " " << (test != test3) << " " << (test < test3) << " " << (test <= test3) << " " << (test > test3) << " " << (test >= test3) << std::endl;

		std::cout << (test == test4) << " " << (test != test4) << " " << (test < test4) << " " << (test <= test4) << " " << (test > test4) << " " << (test >= test4) << std::endl;

		std::cout << (test == test5) << " " << (test != test5) << " " << (test < test5) << " " << (test <= test5) << " " << (test > test5) << " " << (test >= test5) << std::endl;
	}
	return (0);
}
