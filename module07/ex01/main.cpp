/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:22:38 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 19:33:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	templateIterTest( T type, size_t count )
{
	std::cout << B_BLUE "------- Template Iter Test Area ------------" END\
		<< std::flush << std::endl;
	std::cout << "arrType[5] Before: " << std::flush << std::endl;
	iter(type, count, printIter);
	iter(type, count, setIter);
	std::cout << "arrType[5] After: " << std::flush << std::endl;
	iter(type, count, printIter);
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl << std::endl;
}

int	main( void )
{
	int		arrInt[] = { 1, 2, 3, 4, 5 };
	char	arrChar[] = { 'a', 'b', 'c', 'd', 'e' };
	double	arrDouble[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::string	arrString[] = { "Gorkem", "Sever", "Ahmet", "Karaca", ""};

	templateIterTest(arrInt, 5);
	templateIterTest(arrChar, 5);
	templateIterTest(arrDouble, 5);
	templateIterTest(arrString, 5);
}