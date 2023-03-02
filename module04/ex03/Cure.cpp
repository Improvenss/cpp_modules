/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:06:09 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 15:10:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "Cure Default Constrcutor called!"\
		<< std::flush << std::endl;
}

Cure::Cure( Cure const &rhs ) : AMateria("cure")
{
	*this = rhs;
	std::cout << "Cure Copy Constrcutor called!"\
		<< std::flush << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Cure Destructor called!"\
		<< std::flush << std::endl;
}

Cure	&Cure::operator=( Cure const &rhs )
{
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Cure Copy Assignment Operator called!"\
		<< std::flush << std::endl;
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << " 's wounds *"\
		<< std::flush << std::endl;
}