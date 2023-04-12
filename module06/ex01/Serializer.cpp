/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:56:10 by gsever            #+#    #+#             */
/*   Updated: 2023/04/04 12:17:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Serializer::Serializer( void )
// {
// 	std::cout << "Serializer Default Constructor called: "\
// 		<< std::flush << std::endl;
// }

// Serializer::~Serializer( void )
// {
// 	std::cout << "Serializer Destructor called: "\
// 		<< std::flush << std::endl;
// }

/**
 * @brief Data* to uintptr_t
 * 
 * It takes a pointer and converts it to the unsigned long type uintptr_t.
 * @param ptr 
 * @return uintptr_t 
 */
uintptr_t	Serializer::serialize( Data *ptr )
{
	std::cout << "Serialized: " << ptr->studentName\
		<< std::flush << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief uintptr_t to data*
 * 
 * it takes an unsigned long parameter and converts it to a pointer to data.
 * @param raw 
 * @return data 
 */
Data	*Serializer::deseralize( uintptr_t raw )
{
	// reinterpret_cast<Data *>(raw);
	std::cout << "Deserialized: " << raw << std::flush << std::endl;
	return (reinterpret_cast<Data *>(raw));
}