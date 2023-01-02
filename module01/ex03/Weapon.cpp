/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:33:35 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 16:54:49 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

std::string	&getType( void ) const
{
	return (_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}