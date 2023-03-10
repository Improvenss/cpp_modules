/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 20:48:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * -try-catch-throw(), for memory allocation-
 * @link https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c
 * @link https://www.geeksforgeeks.org/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
 * ------------------------------------------
 */
Cat::Cat( void ) : AAnimal("Cat")
{
	std::cout << "Cat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
	try
	{
		this->_brain = new Brain();
		std::cout << GREEN "Memory is allocated 'Successfully'!" END\
			<< std::flush << std::endl;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Memory Allocation is failed: " << e.what() << "bytes: "\
			<< sizeof(Brain) << std::flush << std::endl;
	}
}

// Cat::Cat( std::string name ) : AAnimal("Cat")
// {
// 	std::cout << "Cat Name Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

// Cat::Cat( const Cat &rhs ) : AAnimal(rhs.type)
// {
// 	std::cout << "Cat Copy Constructor called: " << this->type\
// 		<< std::flush << std::endl;
// }

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called: " << this->type\
		<< std::flush << std::endl;
	delete this->_brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}