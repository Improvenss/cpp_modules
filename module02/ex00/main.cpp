/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:28:53 by gsever            #+#    #+#             */
/*   Updated: 2023/01/04 16:49:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief 
 * 
 * @note Search Fixed Point Number
 * @link https://www.youtube.com/watch?v=Oj3jPxssY9U
 * @return int 
 */
int	main()
{
	Fixed	a;// Default Constructor.
	Fixed	b(a);// Copy Constructor.
	Fixed	c;// Default Constructor.

	c = b;// Copy assignment operator.

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);// Destructor.
}
