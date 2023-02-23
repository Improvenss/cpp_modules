/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:43 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 17:44:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat Default Constructor called: " << this->type\
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