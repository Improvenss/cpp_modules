/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:39:43 by gsever            #+#    #+#             */
/*   Updated: 2023/03/21 14:50:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include "Colors.hpp"

/**
 * @brief Special own std::list<int> and number count class.
 * 
 * @fn getList(): Getting Span's inside std::list<int>.
 * @fn printList(): Printing inside std::list<int> every number.
 * @fn addNumber(n): Adding just one new number to inside Span->_list.
 * @fn addNumber(itBegin, itEnd): Adding own std::list<int>'s begin to end
 *  number to inside Span->_list.
 * @fn shortestSpan(): Printing minimum 2 number's values 'farki'.
 *  Numbers; 1 4 92 3999: -> 4 - 1 = 3 -> printing 3
 * @fn longestSpan(): Printing minimum and max number's values 'farki'.
 *  Numbers; 1 4 92 3999: -> 3999 - 1 = 3998 -> printing 3998
 */
class Span
{
	private:
		std::list<int>	_list;
		unsigned int	_numberCount;
		Span( void );
	public:
		Span( unsigned int );
		Span( const Span &rhs );
		~Span( void );

		const std::list<int>	*getList( void ) const; // Getting <int> list type with '*'.
		static void				printList( const std::list<int> *rhs,
			std::string message );
		void					addNumber( int n );
		void					addNumber( std::list<int>::const_iterator itBegin,
			std::list<int>::const_iterator itEnd );
		unsigned int			shortestSpan( void ) const;
		unsigned int			longestSpan( void ) const;
};

std::ostream	&operator<<( std::ostream &os, const Span &rhs );

#endif // SPAN_HPP