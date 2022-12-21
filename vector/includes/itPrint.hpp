#ifndef ITPRINT_HPP
# define ITPRINT_HPP

template<class It>
void	itPrint(It start, It end)
{
	for (;start != end; start++)
	{
		std::cout << *start << std::endl;
	}
}

#endif
