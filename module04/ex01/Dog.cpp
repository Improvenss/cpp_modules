/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 17:44:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * @link https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c
 * 
 */
Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default Constructor called: " << this->type\
		<< std::flush << std::endl;
	try
	{
		this->_brain = new Brain();
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Memory Allocation is failed: " << e.what() << "bytes: "\
			<< sizeof(Brain) << std::endl;;
	}
	
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
	delete this->_brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Hav Hav Hav: " << this->type\
		<< std::flush << std::endl;
}