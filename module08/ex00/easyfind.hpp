/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:17:59 by gsever            #+#    #+#             */
/*   Updated: 2023/04/05 15:19:35 by gsever           ###   ########.fr       */
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
	if (std::find(container.begin(), container.end(), value) != container.end())
		std::cout << B_GREEN "Found!" END << std::flush << std::endl;
	else
		std::cout << B_RED "Not Found!" END << std::flush << std::endl;
}

template<typename T>
// void	printArray( T &arr, std::vector<int>::iterator foundNum )
// void	printArray( T &arr, std::vector<int> foundNum )
void	printArray( T &arr )
{
	int	i = -1;

	std::cout << "Array For: " << std::flush;
	// for (i = 0; arr[i + 6] != '\0'; i++) // i + 2 because default
	for (i = 0; arr[i] != '\0'; i++) // i + 2 because default
	{
		std::cout << arr[i] << std::flush;
		if (arr[i + 1] != '\0')
			std::cout << ", " << std::flush;
	}
	std::cout << std::flush << std::endl;
	std::cout << "Array While: " << std::flush;
	i = -1;
	// while (arr[++i + 6] != '\0')
	while (arr[++i] != '\0')
	{
		// if (arr[i] == foundNum)
		// 	std::cout << B_GREEN "[" << arr[i] << "]" << std::flush;
		// else
			std::cout << arr[i] << std::flush;
		// if (arr[i + 7] != '\0')
		if (arr[i + 1] != '\0')
			std::cout << ", " << std::flush;
	}
	std::cout << std::flush << std::endl;
}

#endif // EASYFIND_HPP