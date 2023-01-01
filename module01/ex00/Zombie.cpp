/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:10:23 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 00:54:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "zombiler patlatilacak" << std::flush << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::flush << std::endl;
}
