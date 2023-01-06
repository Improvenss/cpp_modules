/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:43 by gsever            #+#    #+#             */
/*   Updated: 2023/01/06 15:34:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief 
 * 
 * @return int 
 */
int	main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	{
		Fixed		c;
		Fixed		cSmall;

		c = 10;
		cSmall = 5;
		std::cout << "b: " << a << std::endl;
		std::cout << "cSmall: " << cSmall << std::endl;
			std::cout << "cSmall + a: " << cSmall + c << std::endl;
		std::cout << "cSmall - a: " << cSmall - c << std::endl;
		std::cout << "cSmall * a: " << cSmall * c << std::endl;
		std::cout << "cSmall / a: " << cSmall / c << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016