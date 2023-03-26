/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:17:35 by gsever            #+#    #+#             */
/*   Updated: 2023/03/26 16:01:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief This .hpp file normal 'Header File'.
 * 
 */
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <stack>
# include <deque>
# include "Colors.hpp"
// # include "MutantStack.tpp" // Need to be include after this 'templates'.

/**
 * @brief 
 * 
 * @note template universal usage;
 * @link https://cplusplus.com/reference/stack/stack/
 * 
 * @note STL meaning;
 * @link https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
 * 
 * @note std::deque -> meaning; Double Ended Queue(cift uclu sira).
 * @link https://cplusplus.com/reference/deque/deque/
 * 
 * @note std::stack -> meaning;
 * @link https://en.cppreference.com/w/cpp/container/stack
 * 
 * @tparam T 
 * @tparam Container 
 */
template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack( void ); // Default Constructor.
		MutantStack( const MutantStack &rhs ); // Copy Constructor.
		~MutantStack( void ); // Destructor.

		MutantStack	&operator=( const MutantStack &rhs ); // Copy Assignment Operator Overload.
		// MutantStack<T, Container>	&operator=( const MutantStack<T, Container> &rhs );

		typedef typename Container::iterator	iterator;
		iterator	begin( void ) { return (this->c.begin()); }
		iterator	end( void ) { return (this->c.end()); }
		// Container::iterator	begin( void );
};

# include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP