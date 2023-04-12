/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:03:16 by gsever            #+#    #+#             */
/*   Updated: 2023/04/05 13:16:40y gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// template<typename T>
// class	asdf
// {
// 	T	al;
// };

/**
 * @brief 
 * 
 * @note std::vector's man page samples.
 * @link https://www.geeksforgeeks.org/vector-in-cpp-stl/
 * @link https://www.geeksforgeeks.org/creating-a-vector-of-class-objects-in-cpp/
 * @link https://stackoverflow.com/questions/73651580/c-vector-with-two-parameters
 * 
 * @note std::list's man page samples.
 * @note std::list<>func(param1, param2); // With 2 parameter constructor.
		(3) range constructor
	Constructs a container with as many elements as the range [first,last),
	 with each element constructed from its corresponding element in that range,
	 in the same order.
 * @link https://cplusplus.com/reference/list/list/list/
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main( int argc, char **argv )
{
	// asdf<int>	Sample; // We are creating 'template' class.
	// (void)Sample;
	if (argc != 2)
	{
		std::cout << "You must be enter just one arguman."\
			<< std::flush << std::endl;
		std::cout << "Sample: ./easyfind 5" << std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	// int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000, 235923, 11111, 99999, 88};
	int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000, 235923, 11111, 99999, 88, 6666666, 177, 23234};
	// @note Biggering array with half half.

	printArray(arr);
	std::cout << "Sizeof arr: " << sizeof(arr) << std::flush << std::endl;
	std::cout << "Sizeof arr/4: " << sizeof(arr) / sizeof(int) << std::flush << std::endl;
	// std::cout << "Adress arr: " << arr << std::flush << std::endl;
	// std::cout << B_BLUE "---------- Default Int Array Area ----------" END\
	// 	<< std::flush << std::endl;
	// easyfind(arr, std::atoi(argv[1]));
	// std::cout << B_BLUE "--------------------------------------------" END\
	// 	<< std::flush << std::endl;

	std::cout << B_BLUE "----------- Vector Int Array Area ----------" END\
		<< std::flush << std::endl;
	std::vector<int>	vectorInt(arr, arr + sizeof(arr) / sizeof(int));
	// std::vector<int>helloFriend(arr, arr + sizeof(arr) / sizeof(int));
	easyfind(vectorInt, std::atoi(argv[1]));
	// easyfind(helloFriend, std::atoi(argv[1]));
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl;

	std::cout << B_BLUE "------------ List Int Array Area -----------" END\
		<< std::flush << std::endl;
	std::list<int>	listInt(arr, arr + sizeof(arr) / sizeof(int)); // Creating 
	easyfind(listInt, std::atoi(argv[1]));
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl;
	return (EXIT_SUCCESS);
}