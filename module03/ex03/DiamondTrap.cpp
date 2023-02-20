/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:31:11 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 21:40:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(),\
	ScavTrap(), _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name),\
	FragTrap(name), ScavTrap(name), _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Name Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &rhs ) : ClapTrap(rhs),\
	FragTrap(rhs), ScavTrap(rhs), _name(rhs._name)
{
	std::cout << "DiamondTrap Copy Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor called: " << this->_name\
		<< std::flush << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &rhs )
{
	ClapTrap::operator=(rhs);
	std::cout << "DiamondTrap Copy Assignment Operator called: "\
		<< this->_name << std::flush << std::endl;
	return (*this);
}

void	DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap name: " << this->_name\
		<< std::flush << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name\
		<< std::flush << std::endl;
}