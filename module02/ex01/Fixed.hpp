/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:32:52 by gsever            #+#    #+#             */
/*   Updated: 2023/02/21 17:41:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>// just roundf() allowed.
# include <fstream>

class	Fixed
{
	private:
		int					_fixPoint;
		static const int	_fractBits = 8;
	public:
		Fixed( void );// Default Constructor.
		Fixed( const int numberInt);// Int Constructor.
		Fixed( const float numberFloat );// Float Constructor.
		Fixed( const Fixed &old_class );// Copy Constructor.
		Fixed &operator=( const Fixed &old_class );// Copy assignment operator.
		~Fixed( void );// Destructor.

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<( std::ostream &foo, Fixed const &bar );

#endif