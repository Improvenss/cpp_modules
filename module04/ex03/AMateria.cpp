/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:52 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 16:14:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AMateria.cpp
 * @author Görkem SEVER (gsever)
 * @brief A(Abstract Class) material class's func()s.
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "AMateria.hpp"

AMateria::AMateria( void ) : type("Default")
{
	// std::cout << "AMateria Default Constructor called: " << this->type\
	// 	<< std::flush << std::endl;
}

AMateria::AMateria( std::string const &type ) : type(type)
{
	// std::cout << "AMateria Type Constructor called: " << this->type\
	// 	<< std::flush << std::endl;
}

AMateria::AMateria( AMateria const &rhs ) : type(rhs.type)
{
	// std::cout << "AMateria Copy Constructor called: " << this->type\
	// 	<< std::flush << std::endl;
}

AMateria::~AMateria( void )
{
	// std::cout << "AMateria Destructor called: " << this->type\
	// 	<< std::flush << std::endl;
}

std::string const	&AMateria::getType( void ) const
{
	return (this->type);
}

AMateria	*AMateria::clone( void ) const
{
	return ((AMateria*)this);
}

void	AMateria::use( ICharacter &target )
{
	std::cout << "AMateria " << this->type << " used on "\
		<< target.getName() << std::flush << std::endl;
}