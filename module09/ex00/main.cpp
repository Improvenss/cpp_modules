/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:46:54 by gsever            #+#    #+#             */
/*   Updated: 2023/03/26 20:40:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief 
 * 
 * @note Standard Containers;
 * @link https://www.geeksforgeeks.org/containers-cpp-stl/
 * 
 */
int	main( int argc, char **argv )
{
	try
	{
		(void)argv;
		if (argc != 2)
			throw (std::invalid_argument("You must be enter just one arguman!"));
		if (argv)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}