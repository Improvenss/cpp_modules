/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:30:37 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 16:24:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const &name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	// std::cout << "Character Name Constructor called: " << this->_name\
	// 	<< std::flush << std::endl;
}

Character::Character( Character const &rhs ) : _name(rhs._name)
{
	// for (int i = 0; i < 4; i++)
	// 	this->_inventory[i] = NULL;
	*this = rhs;
	// std::cout << "Character Copy Constructor called: " << this->_name\
	// 	<< std::flush << std::endl;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	// std::cout << "Character Destructor called: " << this->_name\
	// 	<< std::flush << std::endl;
}

Character	&Character::operator=( Character const &rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	// std::cout << "Character Copy Assignment Operator called: " << this->_name\
	// 	<< std::flush << std::endl;
	return (*this);
}

std::string const	&Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip( AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] == NULL)
		{
			// std::cout << GREEN "Character " << this->_name\
			// 	<< " equipped with " << m->getType() << END\
			// 	<< std::flush << std::endl;
			this->_inventory[i] = m;
			return ;
		}
	// std::cout << GREEN "Character " << this->_name\
		// << " can't equip " END << std::flush << std::endl;
}

void	Character::unequip( int idx )
{
	if (this->_inventory[idx])
	{
		// delete this->_inventory[idx];
		// std::cout << RED "Character " << this->_name << " unequipped "\
		// 	<< this->_inventory[idx]->getType()<< " material." END\
		// 	<< std::flush << std::endl;
		this->_inventory[idx] = NULL;
	}
	// else
		// std::cout << RED "Character " << this->_name << " can't unequip " END\
		// 	<< std::flush << std::endl;
}

void	Character::use( int idx, ICharacter &target )
{
	if (this->_inventory[idx])
	{
		// std::cout << YELLOW "Character " << this->_name << " uses "\
		// 	<< this->_inventory[idx]->getType() << END\
		// 	<< std::flush << std::endl;
		this->_inventory[idx]->use(target);
	}
	// else
	// 	std::cout << YELLOW "Character " << this->_name << " can't use " END\
	// 		<< std::flush << std::endl;
}