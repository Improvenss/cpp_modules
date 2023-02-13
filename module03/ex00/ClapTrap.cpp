/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:37:00 by gsever            #+#    #+#             */
/*   Updated: 2023/02/13 20:03:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object.
 * 
 * Default Constructor.
 */
ClapTrap::ClapTrap( void ) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called: " << _name <<  std::flush << std::endl;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 * 
 * Destructor.
 */
ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called: " << _name << std::flush << std::endl;
}

void	ClapTrap::attack( const std::string &target )
{
	if ()
}

void	ClapTrap::takeDamage( unsigned int amount )
{

}

bool	ClapTrap::isALive( void )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " already dead!" << std::flush << std::endl;
		return (false);
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy point!" << std::flush << std::endl;
		return (false);
	}
	return (true);
}