#ifndef CUSTOMCOMPARE_HPP
# define CUSTOMCOMPARE_HPP

template<class type>
class customCompare
{
	public:
		customCompare(void){}
		customCompare(customCompare const & src){(void)src;}
		~customCompare(void){}

		customCompare	operator=(customCompare const & rhs){(void)rhs; return (*this);}

		bool	operator()(type const & lhs, type const & rhs) const
		{
			return (*lhs < *rhs);
		}
};

#endif
