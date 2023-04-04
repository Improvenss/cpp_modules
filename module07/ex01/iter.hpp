/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:23:22 by gsever            #+#    #+#             */
/*   Updated: 2023/04/04 14:15:36 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include "Colors.hpp"

template<typename T>
void	setIter( T &i )
{
	i = 42;
}

template<typename T>
void	printIter( T &i )
{
	std::cout << i << std::flush << std::endl;
}

template<typename T>
void	iter( T *array, size_t length, void	(*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif // ITER_HPP