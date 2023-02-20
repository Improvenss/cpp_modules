/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 23:50:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

// Dog::Dog( std::string name ) : Animal("Dog")
// {
// 	std::cout << "Dog Name Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

// Dog::Dog( const Dog &rhs ) : Animal(rhs.type)
// {
// 	std::cout << "Dog Copy Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called: " << this->type\
		<< std::flush << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Hav Hav Hav: " << this->type\
		<< std::flush << std::endl;
}