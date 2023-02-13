/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:48:28 by gsever            #+#    #+#             */
/*   Updated: 2023/02/13 16:37:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		// Anything else useful etc. -> double sample;
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point &rhs );
		~Point( void );

		Point &operator=( const Point &rhs );

		Fixed	getPointX( void ) const;
		Fixed	getPointY( void ) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

// std::ostream	&operator<<( std::ostream &lhs, Point const &rhs );

#endif