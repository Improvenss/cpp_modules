/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:42:55 by gsever            #+#    #+#             */
/*   Updated: 2023/04/05 14:15:37 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ) : _numberCount(n)
{
	// std::cout << "Span uint Constructor called!" << std::flush << std::endl;
}

Span::Span( const Span &rhs )
{
	*this = rhs;
}

Span::~Span( void )
{
	// std::cout << "Span Destructor called!" << std::flush << std::endl;
}

const std::list<int>	*Span::getList( void ) const
{
	return (&this->_list);
}

void	Span::printList( const std::list<int> *rhs, std::string message )
{
	std::cout << message << YELLOW "List:" << std::flush;
	// if (rhs->size() < 2)
	if (rhs->empty()) // Checking, if list are empty.
		std::cerr << B_RED " List Empty!" END << std::flush;
		// throw (std::out_of_range("Span::printList: Empty List!"));
	for (std::list<int>::const_iterator it = rhs->begin(); it != rhs->end(); it++)
		std::cout << " " << *it << std::flush;
	std::cout << END << std::flush << std::endl << std::endl;
}

void	Span::addNumber( int n )
{
	if (this->_list.size() > this->_numberCount)
		throw (std::out_of_range("Span: Span::addNumber: List Is Full!"));
	this->_list.push_back(n);
}

/**
 * @brief 
 * 
 * @note std::list's insert();
 * @link https://cplusplus.com/reference/list/list/insert/
 * 
 * @param itBegin 
 * @param itEnd 
 */
void	Span::addNumber( std::list<int>::const_iterator itBegin,
	std::list<int>::const_iterator itEnd )
{
	if (this->_list.size() > this->_numberCount)
		throw (std::out_of_range("Span: Span::addNumber: List Is Full!"));
	this->_list.insert(this->_list.end(), itBegin, itEnd);
}

unsigned int	Span::shortestSpan( void ) const
{
	unsigned int	min = Span::longestSpan();

	if (this->_list.size() < 2)
		throw (std::out_of_range("Span: Span::shortestSpan: List Is Empty!"));
	for (std::list<int>::const_iterator it = this->_list.begin(); it != this->_list.end(); it++)
		for (std::list<int>::const_iterator it2 = this->_list.begin(); it2 != this->_list.end(); it2++)
		{
			if (it == it2)
				continue ;
			if (std::abs(*it2 - *it) < static_cast<int>(min))
				min = std::abs(*it2 - *it); // abs -> Absolute Value = Mutlak Deger
		}
	return (min);
}

unsigned int	Span::longestSpan( void ) const
{
	if (this->_list.size() < 2)
		throw (std::out_of_range("Span: Span::longestSpan: List Is Empty!"));
	return (*std::max_element(this->_list.begin(), this->_list.end())
		- *std::min_element(this->_list.begin(), this->_list.end()));
}

std::ostream	&operator<<( std::ostream &os, const Span &rhs )
{
	for (std::list<int>::const_iterator it = rhs.getList()->begin(); it != rhs.getList()->end(); it++)
		os << *it << " " << std::flush;
	return (os);
}