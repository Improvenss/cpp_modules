/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/13 18:10:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief 
 * 
 * @link https://umitsen.wordpress.com/2013/04/07/nokta-ucgenin-icinde-mi-degil-mi-test-etme/
 * @link https://www.math10.com/en/geometry/geogebra/geogebra.html
 * 
 * @return int 
 */
int	main()
{
	Point	a;// (0, 0)
	Point	b(3.0, 4.0);// (3, 4)
	Point	c(4.0, 0.0);// (4, 0);
	Point	p(3.75, 1.0);// 3.75 inside, 3.76 outside

	if (bsp(a, b, c, p) == true)
		std::cout << "The Point \"INSIDE\" the triangle" << std::flush << std::endl;
	else
		std::cout << "The Point \"OUTSIDE\" the triangle" << std::flush << std::endl;
	return (0);
}