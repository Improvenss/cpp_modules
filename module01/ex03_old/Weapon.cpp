/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 12:31:44 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
	this->setType(type);
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}