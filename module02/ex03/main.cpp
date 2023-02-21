/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/22 01:55:21 by gsever           ###   ########.fr       */
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
	Point	p(3.75, 1.0);// 3.75 inside
	// Point	p(3.76, 1.0);// 3.76 outside

	std::cout << "--------- First Style (Location) --------"\
		<< std::flush << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN "The Point bsp(): \"INSIDE\" the triangle" END\
			<< std::flush << std::endl;
	else
		std::cout << RED "The Point bsp(): \"OUTSIDE\" the triangle" END\
			<< std::flush << std::endl;

	std::cout << "--------- Second Style (Area) --------"\
		<< std::flush << std::endl;

	if (bspArea(a, b, c, p) == true)
		std::cout << GREEN "The Point bsp(): \"INSIDE\" the triangle" END\
			<< std::flush << std::endl;
	else
		std::cout << RED "The Point bsp(): \"OUTSIDE\" the triangle" END\
			<< std::flush << std::endl;
	return (0);
}