#if ISFT == 1
# define NAMESPACE ft
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "ConstClass.hpp"
#include "timer.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		volatile int	x = 0;
		std::cout << "*******   int vector iterator constructor   *******" << std::endl;
		{
			int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			for (volatile int i = 0; i < 100; i++)
			{
				std::cout << i << std::endl;
				NAMESPACE::vector<int>	test(tab, tab+10);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		std::cout << "*******   std::string vector iterator constructor   *******" << std::endl;
		{

			for (volatile int i = 0; i < 100; i++)
			{
				std::istringstream	str("0.0 0.1 1.2 5.3 6.4 8.9 10.4");
				std::cout << i << std::endl;
				NAMESPACE::vector<double>	test((std::istream_iterator<double>(str)), (std::istream_iterator<double>()));

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		std::cout << "*******   ConstClass<int> vector iterator constructor   *******" << std::endl;
		{
			ConstClass<int>	tab[] = {ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10)};
			for (volatile int i = 0; i < 100; i++)
			{
				std::cout << i << std::endl;
				NAMESPACE::vector<ConstClass<int> >	test(tab, tab+3);

				if (!test.size())
					x += 1;
				else
					x += 2;

			}
		}
		std::cerr << x << std::endl;
	}
	else if (ac == 2 && std::string(av[1]) == "benchmark")
	{
		volatile int	x = 0;
		timer			timing;

		std::cout << "benchmark" << std::endl;

		{
			int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};
			for (volatile int i = 0; i < 33000; i++)
			{
				NAMESPACE::vector<int>	test(tab, tab+172);

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		{
			for (volatile int i = 0; i < 33000; i++)
			{
			std::istringstream	str("0.0 0.1 1.2 5.3 6.4 8.9 10.4 25.1 21.2 89.6 256.4 2.1 0.2 0.6 0.8 0.9 0.4 0.6 0.2 0.1 8.6 9.56 52.36 4587.6 646.0 254.47 546.54 68.54 2145.87 215.849 54.5467 78.489 589.6894 548.46 0.0 0.1 1.2 5.3 6.4 8.9 10.4 25.1 21.2 89.6 256.4 2.1 0.2 0.6 0.8 0.9 0.4 0.6 0.2 0.1 8.6 9.56 52.36 4587.6 646.0 254.47 546.54 68.54 2145.87 215.849 54.5467 78.489 589.6894 548.46 0.0 0.1 1.2 5.3 6.4 8.9 10.4 25.1 21.2 89.6 256.4 2.1 0.2 0.6 0.8 0.9 0.4 0.6 0.2 0.1 8.6 9.56 52.36 4587.6 646.0 254.47 546.54 68.54 2145.87 215.849 54.5467 78.489 589.6894 548.46 0.0 0.1 1.2 5.3 6.4 8.9 10.4 25.1 21.2 89.6 256.4 2.1 0.2 0.6 0.8 0.9 0.4 0.6 0.2 0.1 8.6 9.56 52.36 4587.6 646.0 254.47 546.54 68.54 2145.87 215.849 54.5467 78.489 589.6894 548.46 0.0 0.1 1.2 5.3 6.4 8.9 10.4 25.1 21.2 89.6 256.4 2.1 0.2 0.6 0.8 0.9 0.4 0.6 0.2 0.1 8.6 9.56 52.36 4587.6 646.0 254.47 546.54 68.54 2145.87 215.849 54.5467 78.489 589.6894 548.46");
				NAMESPACE::vector<double>	test((std::istream_iterator<double>(str)), (std::istream_iterator<double>()));

				if (!test.size())
					x += 1;
				else
					x += 2;
			}
		}
		{
			ConstClass<int>	tab[] = {ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710), ConstClass<int>(), ConstClass<int>(2), ConstClass<int>(10), ConstClass<int>(56), ConstClass<int>(42), ConstClass<int>(110), ConstClass<int>(58), ConstClass<int>(289), ConstClass<int>(140), ConstClass<int>(77), ConstClass<int>(222), ConstClass<int>(100), ConstClass<int>(986), ConstClass<int>(542), ConstClass<int>(10545), ConstClass<int>(354), ConstClass<int>(542), ConstClass<int>(8710) };
			for (volatile int i = 0; i < 33000; i++)
			{
				NAMESPACE::vector<ConstClass<int> >	test(tab, tab+144);

				if (!test.size())
					x += 1;
				else
					x += 2;

			}
		}
		std::cout << x << std::endl;
		std::cout << timing.diff() << std::endl;
	}
	else
		return (1);
	return (0);
}
