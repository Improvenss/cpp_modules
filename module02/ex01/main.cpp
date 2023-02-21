/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/21 17:37:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief 
 * 
 * @link https://www.geeksforgeeks.org/constants-in-c-cpp/
 * @return int 
 */
int	main()
{
	Fixed		a;// Default Constructor.
	Fixed const	b(10);// Int Constructor.
	Fixed const	c(42.42f);// Float Constructor.
	Fixed const	d(b);// Copy Constructor.

	a = Fixed(1234.4321f);// Copy assignment operator.

	// std::cout << "123" << std::endl;// '<<' operatoru sonrasinda class alirsa kutuphanede tanimladigimiz &operator<< func() calismis oluyor.
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "5<<8: " << (5 << 8) << std::endl;
	// std::cout << "1<<8: " << (1 << 8) << std::endl;
	// std::cout << ((5 << 8) / (1 << 8)) << std::endl;

	return (0);
}