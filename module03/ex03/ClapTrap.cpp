/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:37:00 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 19:25:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object.
 * 
 * Default Constructor.
 */
ClapTrap::ClapTrap( void ) : _name("Default"), _hitPoints(10),\
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called: "\
		<< this->_name <<  std::flush << std::endl;
}

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 * Name Constructor.
 * @param name 
 */
ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10),\
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name Constructor called: "\
		<< this->_name <<  std::flush << std::endl;
}

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 * Copy Constructor.
 * @param rhs 
 */
ClapTrap::ClapTrap( const ClapTrap &rhs ) : _name(rhs._name),\
	_hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints),\
	_attackDamage(rhs._attackDamage)
{
	std::cout << "ClapTrap Copy Constructor called: "\
		<< this->_name << std::flush << std::endl;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 * 
 * Destructor.
 */
ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called: "\
		<< this->_name << std::flush << std::endl;
}

/**
 * @brief ClapTrap = ClapTrap class equal operator.
 * 
 * Copy Assignment Operator.
 * @param rhs 
 * @return ClapTrap& 
 */
ClapTrap &ClapTrap::operator=( const ClapTrap &rhs )
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "ClapTrap Copy Assignment Operator called: "\
		<< this->_name << std::flush << std::endl;
	return (*this);
}

void	ClapTrap::attack( const std::string &target )
{
	if (!(this->isALive()))
		return ;
	std::cout << YELLOW "ClapTrap " << this->_name << " attacks "\
		<< target << ", causing " << this->_attackDamage\
		<< " points of damage!" END << std::flush << std::endl;
	this->_energyPoints--;
	std::cout << YELLOW "ClapTrap " << this->_name\
		<< " remaining energy point: " << this->_energyPoints\
		<< END << std::flush << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	// if (this->_hitPoints <= 0)
	if (!(this->isALive()))
	{
		std::cout << "ClapTrap " << this->_name << " already dead!"\
			<< std::flush << std::endl;
		return ;
	}
	std::cout << CYAN "ClapTrap " << this->_name << " has taken "\
		<< amount << " points of damage!" END << std::endl;
	if (this->_hitPoints <= amount)
	{
		this->_hitPoints = 0;
		std::cout << PURPLE "ClapTrap " << this->_name\
			<< " died!" END << std::flush << std::endl;
	}
	else
		this->_hitPoints -= amount;
	std::cout << CYAN "ClapTrap " << this->_name << " remaining hit point: "\
		<< this->_hitPoints << END << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!(this->isALive()))
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << GREEN "ClapTrap " << this->_name << " has been repaired of "\
		<< amount << " hit point!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " remaining hit point: "\
		<< this->_hitPoints << std::endl;
	std::cout << "ClapTrap " << this->_name << " remaining energy point: "\
		<< this->_energyPoints << END << std::endl;
}

bool	ClapTrap::isALive( void )
{
	if (this->_hitPoints <= 0)
	{
		std::cout << RED "ClapTrap " << this->_name << " already dead!" END\
			<< std::flush << std::endl;
		return (false);
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy point!"\
			<< std::flush << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::setDamage( unsigned int amount )
{
	this->_attackDamage = amount;
	std::cout << "ClapTrap " << this->_name << " damage setted: "\
		<< this->_attackDamage << std::flush << std::endl;
}

unsigned int	ClapTrap::getDamage( void )
{
	return (this->_attackDamage);
}