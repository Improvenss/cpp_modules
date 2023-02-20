/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:54:44 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 09:53:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Name Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

FragTrap::FragTrap( const FragTrap &rhs ) : ClapTrap(rhs)
{
	std::cout << "FragTrap " << "Copy Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called: " << this->_name\
		<< std::flush << std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &rhs )
{
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap " << "Copy Assignment Operator called: "\
		<< this->_name << std::flush << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " positive high fives request!"\
		<< std::flush << std::endl;
}