/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:10:49 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 15:14:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Ice Default Constrcutor called!"\
		<< std::flush << std::endl;
}

Ice::Ice( Ice const &rhs ) : AMateria("ice")
{
	*this = rhs;
	std::cout << "Ice Copy Constrcutor called!"\
		<< std::flush << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "Ice Destructor called!"\
		<< std::flush << std::endl;
}

Ice	&Ice::operator=( Ice const &rhs )
{
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Ice Copy Assignment Operator called!"\
		<< std::flush << std::endl;
	return (*this);
}

AMateria	*Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"\
		<< std::flush << std::endl;
}