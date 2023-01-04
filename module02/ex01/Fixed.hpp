/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:32:52 by gsever            #+#    #+#             */
/*   Updated: 2023/01/04 18:08:31 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>// just roundf() allowed.

class	Fixed
{
	private:
		int					_fixPoint;
		static const int	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const int numberInt);
		Fixed( const float numberFloat );
		Fixed( const Fixed &old_class );
		Fixed &operator=( const Fixed &old_class );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream & foo, )

#endif