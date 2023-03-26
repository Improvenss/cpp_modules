/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:22:38 by gsever            #+#    #+#             */
/*   Updated: 2023/03/24 15:03:23 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	templateIterTest( T type, size_t count )
{
	std::cout << B_BLUE "------- Template Iter Test Area ------------" END\
		<< std::flush << std::endl;
	std::cout << GREEN "Type ID: [" << typeid(T).name() << "]" END\
		<< std::flush << std::endl;
	std::cout << "arrType[5] Before: " << std::flush << std::endl;
	iter(type, count, printIter);
	iter(type, count, setIter);
	std::cout << "arrType[5] After: " << std::flush << std::endl;
	iter(type, count, printIter);
	std::cout << B_BLUE "--------------------------------------------" END\
		<< std::flush << std::endl << std::endl;
}

/**
 * @brief This func() can't be int template, this templates can be
 *  "Template Classes'.
 * 
 * @tparam hello 
 * @param intNumber 
 */
// template<int hello>
// void	exampleTemplateParam( hello intNumber)
// {
// 	std::cout << "exampleTemplateParam: " << intNumber << std::flush << std::endl;
// }

template<typename T, typename C>
void	exampleOneTwo( T type, C count )
{
	std::cout << "exampleOneTwo: " << type << " and " << count\
		<< std::flush << std::endl;
}

/**
 * @brief If have syntax error or something; compiler will not show
 *  any error, because this functions are EN: 'Template' TR: 'Sablon'.
 * 
 * @tparam asdf 
 * @param foo 
 */
template<typename asdf>
void	exampleAsdf( asdf foo, asdf bar )
{
	std::cout << "exampleAsdf: " << foo << bar << std::flush << std::endl;
}

/**
 * @brief 
 * 
 * template<typename asdf>
 * void	foo( T bar ) { we can't use -> foo<int>(5)}
 * 
 * @return int 
 */
int	main( void )
{
	int		arrInt[] = { 1, 2, 3, 4, 5 };
	char	arrChar[] = { 'a', 'b', 'c', 'd', 'e' };
	double	arrDouble[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::string	arrString[] = { "Gorkem", "Sever", "Ahmet", "Karaca", ""};

	exampleAsdf<int>(42, 43); // We can use this func<template>() with 2+ same type template parameter.
	exampleAsdf<char>(42, 43);
	// templateIterTest<int>(arrInt, 5); // But we can't use this <> with 2+ different parameter.
	exampleOneTwo(42, "Gorkem");
	// exampleTemplateParam(42);
	templateIterTest(arrInt, 5);
	templateIterTest(arrChar, 5);
	templateIterTest(arrDouble, 5);
	templateIterTest(arrString, 5);
}