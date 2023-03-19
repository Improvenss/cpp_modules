/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:22:04 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 21:06:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "Colors.hpp"

// # define INT	0
// # define CHAR	1
// # define FLOAT	2
// # define DOUBLE	4

template<typename T>
class Array
{
	private:
		T		*_arr;
		size_t	_size;
	public:
		Array( void ) : _arr(new T()), _size(0) {};
		Array( unsigned int n ) : _arr(new T[n]), _size(n) {};
		Array( const Array &rhs ) : _arr(new T[rhs.getSize()]), _size(rhs.getSize())
		{
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = rhs._arr[i];
		}
		~Array( void ) { delete []_arr; }

		Array	&operator=( const Array &rhs )
		{
			if (this != &rhs)
			{
				delete []this->_arr;
				this->_arr = new T[rhs.getSize()];
				this->_size = rhs.getSize();
				for (unsigned int i = 0; i < this->_size; i++)
					this->_arr[i] = rhs._arr[i];
			}
			return (*this);
		}

		T	&operator[]( unsigned int i ) const
		{
			if (i >= this->_size)
				throw (OutOfBoundsException());
			return (this->_arr[i]);
		}

		unsigned int	getSize( void ) { return (this->_size); }
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char	*what() const throw() { return ("Index is out of bounds!"); }
	};
};

template<typename T>
std::ostream	&operator<<( std::ostream &os, Array<T> &rhs )
{
	for (unsigned int i = 0; i < rhs.getSize(); i++)
		os << rhs[i] << " " << std::flush;
	return (os);
}

#endif // ARRAY_HPP