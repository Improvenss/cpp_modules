/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:33:02 by gsever            #+#    #+#             */
/*   Updated: 2023/02/22 12:26:58 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed::Fixed object
 * Default Constructor.
 */
Fixed::Fixed( void ) : _fixPoint(0)
{
	std::cout << "Default constructor called" << std::flush << std::endl;
	// this->_fixPoint = 0;
}

// Fixed::Fixed( const int numberInt ) : _fixPoint(numberInt)
Fixed::Fixed( const int numberInt ) : _fixPoint(numberInt << _fractBits)
{
	std::cout << "Int constructor called" << std::flush << std::endl;
	// this->_fixPoint = numberInt;
}

Fixed::Fixed( const float numberFloat) : _fixPoint(std::roundf(\
	numberFloat * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::flush << std::endl;
	// this->_fixPoint = numberFloat;
}

/**
 * @brief Copy Construct a new Fixed::Fixed object
 * Copy Constructor.
 * @link https://www.geeksforgeeks.org/copy-constructor-in-cpp/
 * @param old_class 
 */
Fixed::Fixed( const Fixed &old_class)
{
	std::cout << "Copy constructor called" << std::flush << std::endl;
	*this = old_class;
	// this->_fixPoint = old_class._fixPoint;
}

/**
 * @brief Copy assignment a new Fixed::Fixed object
 * Copy assignment operator.
 * @link https://en.cppreference.com/w/cpp/language/copy_assignment
 * @param old_class 
 * @return Fixed& 
 */
Fixed &Fixed::operator=( const Fixed &old_class )
{
	std::cout << "Copy assignment operator called" << std::flush << std::endl;
	this->_fixPoint = old_class.getRawBits();
	// this->_fixPoint = old_class._fixPoint;
	return (*this);
}

/**
 * @brief Destroy the Fixed::Fixed object
 * Destructor operator.
 */
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::flush << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::flush << std::endl;
	return (this->_fixPoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::flush << std::endl;
	this->_fixPoint = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() >> _fractBits);
}

std::ostream	&operator<<(std::ostream &foo, Fixed const &bar )
{
	foo << bar.toFloat();
	return (foo);
}