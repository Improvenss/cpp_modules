/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:20 by gsever            #+#    #+#             */
/*   Updated: 2023/02/27 14:07:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

/**
 * @brief 
 * 
 * Abstract Class(Soyutlama) vs Interface(Arayuz)
 * 
 * @return int 
 */
int	main()
{
	// IMateriaSource	*src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	IMateriaSource *asdf = new IMateriaSource();

	// ICharacter	*me = new Character("me");

	// AMateria	*tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter	*bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;

	// return 0;
}