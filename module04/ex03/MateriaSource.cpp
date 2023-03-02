/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:53 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 16:17:41 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	// std::cout << "MateriaSource Default Constructor called!"\
	// 	<< std::flush << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const &rhs )
{
	*this = rhs;
	// std::cout << "Materiasource Copy Constructor called!"\
	// 	<< std::flush << std::endl;
}

MateriaSource::~MateriaSource( void )
{
	// std::cout << "Materiasource Destructor called!"\
	// 	<< std::flush << std::endl;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs )
{
	if (this != &rhs)
		for (int i = 0; i < 4; i++)
			this->_materias[i] = rhs._materias[i];
	// std::cout << "MateriaSource Copy Assignment Operator called!"\
	// 	<< std::flush << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			// std::cout << "MateriaSouce learned: " << materia->getType()\
			// 	<< std::flush << std::endl;
			return ;
		}
	}
	// std::cout << "MateriaSource can't learned:" << materia->getType()\
	// 	<< std::flush << std::endl;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	return (NULL);
}

AMateria	*MateriaSource::getMateria( std::string const &type )
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]);
	return (NULL);
}