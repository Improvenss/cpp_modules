/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:48:42 by gsever            #+#    #+#             */
/*   Updated: 2023/01/06 20:17:01 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::flush << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y)
{
	std::cout << "2 param constructor called" << std::flush << std::endl;
}

Point::Point( const Point &rhs ) : _x(rhs._x.getRawBits()), _y(rhs._y.getRawBits())
{
	std::cout << "Copy constructor called" << std::flush << std::endl;
}

Point	&Point::operator=( const Point &rhs )
{
	std::cout << "Copy assignment operator called" << std::flush << std::endl;
	if (this != &rhs)
	{
		(Fixed)this->_x = rhs.getPointX();
		(Fixed)this->_y = rhs.getPointY();
	}
	return (*this);
}

Point::~Point( void )
{
}


Fixed	Point::getPointX( void ) const
{
	return (this->_x);
}
Fixed	Point::getPointY( void ) const
{
	return (this->_y);
}

// std::ostream	&operator<<(std::ostream &lhs, Point &rhs)
// {
	
// }