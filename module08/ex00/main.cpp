/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:03:16 by gsever            #+#    #+#             */
/*   Updated: 2023/03/20 12:26:03 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "You must be enter just one arguman."\
			<< std::flush << std::endl;
		std::cout << "Sample: ./easyfind 5" << std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	int	arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printArray(arr);
	// std::cout << B_BLUE "---------- Default Int Array Area ----------" END\
	// 	<< std::flush << std::endl;
	// easyfind(arr, std::atoi(argv[1]));
	// std::cout << B_BLUE "--------------------------------------------" END\
	// 	<< std::flush << std::endl;

	std::cout << B_BLUE "----------- Vector Int Array Area ----------" END\
		<< std::flush << std::endl;
	std::vector<int>vectorInt(arr, arr + sizeof(arr) / sizeof(int));
	easyfind(vectorInt, std::atoi(argv[1]));
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl;

	std::cout << B_BLUE "------------ List Int Array Area -----------" END\
		<< std::flush << std::endl;
	std::list<int>listInt(arr, arr + sizeof(arr) / sizeof(int));
	easyfind(listInt, std::atoi(argv[1]));
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl;
	return (EXIT_SUCCESS);
}