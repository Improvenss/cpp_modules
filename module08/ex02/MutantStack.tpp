/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:32:45 by gsever            #+#    #+#             */
/*   Updated: 2023/03/26 16:19:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Template Class's implement file.
 * 
 * This .tpp file for header file's inside 'Template class's'
 *  'implementation' area.
 * 
 */
#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T, class Container>
MutantStack<T, Container>::MutantStack( void )
{
	// std::cout << "MutantStack Default Constructor called!"\
	// 	<< std::flush << std::endl;
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack( const MutantStack &rhs )
{
	// std::cout << "MutantStack Copy Constructor called!"\
	// 	<< std::flush << std::endl;
	*this = rhs;
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack( void )
{
	// std::cout << "MutantStack Destructor called!"\
	// 	<< std::flush << std::endl;
}

template<typename T, class Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=\
	( const MutantStack<T, Container> &rhs )
{
	// std::cout << "MutantStack 'Copy' Assignment Operator called!"\
	// 	<< std::flush << std::endl;
	// if (this != &rhs)
	this = std::stack<T, Container>::operator=(rhs);
	return (*this);
}



#endif // MUTANTSTACK_TPP