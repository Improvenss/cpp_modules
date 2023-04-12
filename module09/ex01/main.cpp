/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:34:46 by gsever            #+#    #+#             */
/*   Updated: 2023/04/12 23:03:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cerr << "You must be enter just one argument."\
			<< std::flush << std::endl;
		std::cerr << "Like -> ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""\
			<< std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		/* code */
		(void)argv;
		
		// while (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << "RPN: Error:" << e.what() << std::flush << std::endl;
	}
	return (EXIT_SUCCESS);
}