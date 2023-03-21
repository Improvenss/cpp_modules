/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:17:59 by gsever            #+#    #+#             */
/*   Updated: 2023/03/20 12:29:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include "Colors.hpp"

template<typename T>
void	easyfind( T &container, int value )
{
	// T	found;

	// found = std::find(container.begin(), container.end(), value);
	// if (found != container.end())
	if (std::find(container.begin(), container.end(), value) != container.end())
		std::cout << B_GREEN "Found!" END << std::flush << std::endl;
	else
		std::cout << B_RED "Not Found!" END << std::flush << std::endl;
	// printArray(container, found);
}

template<typename T>
// void	printArray( T &arr, std::vector<int>::iterator foundNum )
// void	printArray( T &arr, std::vector<int> foundNum )
void	printArray( T &arr )
{
	int	i = -1;

	std::cout << "Array: " << std::flush;
	// for (size_t i = 0; arr[i + 2] != '\0'; i++) // i + 2 because default
	// {
	// 	std::cout << arr[i] << std::flush;
	// 	if (arr[i + 3] != '\0')
	// 		std::cout << ", " << std::flush;
	// }
	// std::cout << std::flush << std::endl;
	while (arr[++i + 2] != '\0')
	{
		// if (arr[i] == foundNum)
		// 	std::cout << B_GREEN "[" << arr[i] << "]" << std::flush;
		// else
			std::cout << arr[i] << std::flush;
		if (arr[i + 3] != '\0')
			std::cout << ", " << std::flush;
	}
	std::cout << std::flush << std::endl;
}

#endif // EASYFIND_HPP