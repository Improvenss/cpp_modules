/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:41:15 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 20:43:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("Default")
{
	std::cout << "AAnimal Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

AAnimal::AAnimal( std::string name ) : type(name)
{
	std::cout << "AAnimal Name Constructor called: " << this->type\
		<< std::flush << std::endl;
}

AAnimal::AAnimal( const AAnimal &rhs ) : type(rhs.type)
{
	std::cout << "AAnimal Copy Constructor called: " << this->type\
		<< std::flush << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal Destructor called: " << this->type\
		<< std::flush << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal makeSound called: " << this->type\
		<< std::flush << std::endl;
}