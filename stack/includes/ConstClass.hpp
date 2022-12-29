/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:17:43 by bdetune           #+#    #+#             */
/*   Updated: 2022/12/16 18:46:25 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTCLASS_HPP
# define CONSTCLASS_HPP
# include <iostream>

template<class T>
class ConstClass
{
	public:
		ConstClass(T const & nb): _val(nb) {}
		ConstClass(void): _val() {}
		ConstClass(ConstClass const & src): _val(src._val){}
		~ConstClass(void){}

		ConstClass & operator=(ConstClass const & rhs){(void)rhs;return(*this);}
		bool operator==(ConstClass const & rhs) const {return (this->_val == rhs._val);}
		bool operator!=(ConstClass const & rhs) const {return (this->_val != rhs._val);}
		bool operator>(ConstClass const & rhs) const {return (this->_val > rhs._val);}
		bool operator>=(ConstClass const & rhs) const {return (this->_val >= rhs._val);}
		bool operator<(ConstClass const & rhs) const {return (this->_val < rhs._val);}
		bool operator<=(ConstClass const & rhs) const {return (this->_val <= rhs._val);}

		T const &	getValue(void) const {return (_val);}
		T const &	operator*(void) const {return (_val);}
	
	private:
		const T	_val;
};

template<class T>
std::ostream &	operator<<(std::ostream & stream, ConstClass<T> const & toprint)
{
	stream << toprint.getValue();
	return (stream);
}

#endif
