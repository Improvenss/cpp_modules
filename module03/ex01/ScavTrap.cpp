/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:58:42 by gsever            #+#    #+#             */
/*   Updated: 2023/02/22 14:58:13 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->isGuardOn = false;
	std::cout << "ScavTrap Default Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	// this->_name = "Default";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->isGuardOn = false;
	std::cout << "ScavTrap Name Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &rhs ) : ClapTrap( rhs )
{
	this->isGuardOn = rhs.isGuardOn;
	std::cout << "ScavTrap Copy Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &rhs )
{
	ClapTrap::operator=(rhs);
	this->isGuardOn = rhs.isGuardOn;
	std::cout << "ScavTrap Copy Assginment Operator called: "\
		<< this->_name << std::flush << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called: "\
		<< this->_name << std::flush << std::endl;
}

void	ScavTrap::attack( const std::string &target )
{
	if (!(this->isALive()))
		return ;
	// ClapTrap::attack(target);
	std::cout << YELLOW "ScavTrap " << this->_name << " attacks "\
		<< target << ", causing " << this->_attackDamage\
		<< " points of damage!" END << std::flush << std::endl;
	this->_energyPoints--;
	std::cout << YELLOW "ScavTrap " << this->_name\
		<< " remaining energy point: " << this->_energyPoints\
		<< END << std::flush << std::endl;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if (this->isGuardOn == true)
		std::cout << "ScavTrap " << this->_name\
			<< " can't be attacked because it's in guard gate mode!"\
			<< std::flush << std::endl;
	else
		ClapTrap::takeDamage(amount);
}

void	ScavTrap::guardGate( void )
{
	if (this->_hitPoints > 0)
	{
		this->isGuardOn = true;
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode."\
			<< std::flush << std::endl;
	}
	else
		std::cout << "ScavTrap "<< this->_name << "can't be guard, because dead!"\
			<< std::flush << std::endl;
}

unsigned int	ScavTrap::getDamage( void )
{
	return (this->_attackDamage);
}