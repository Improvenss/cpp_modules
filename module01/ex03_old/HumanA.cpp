/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:34:24 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 12:41:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


HumanA::HumanA()
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void )
{
	if (this->_weaponSelf != "")
		std::cout << this->_name << " attacks with their " << this->_weaponSelf << std::flush << std::endl;
	else
		std::cout << this->_name << "'s doesn't have a weapon for attack!" << std::flush << std::endl;
}