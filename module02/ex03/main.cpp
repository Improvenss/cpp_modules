/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:43 by gsever            #+#    #+#             */
/*   Updated: 2023/01/06 20:17:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief 
 * 
 * @return int 
 */
int	main()
{

	Point	a;
	Point	b(2.8f, 5.1f);
	Point	c(a);

	a = c;

	// std::cout << "a: " << a << std::flush << std::endl;
	// std::cout << "a: " << std::flush << std::endl;
	// std::cout << "a: " << std::flush << std::endl;
	// std::cout << "a: " << std::flush << std::endl;
	return (0);
}