/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:23 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 12:58:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Constructor called: " << this->type\
		<< std::flush << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called: " << this->type\
		<< std::flush << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miyav Miyav: " << this->type\
		<< std::flush << std::endl;
}