/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:20 by gsever            #+#    #+#             */
/*   Updated: 2023/03/01 18:01:17 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2023-02-28
 * 
 * @link https://www.educba.com/c-plus-plus-interface/
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// #include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
#include "AMateria.hpp"


/**
 * @brief Learning 
 * 
	a) Abstract Classes()
		These are base classes where you have to derive from them and
		 then implement the pure virtual functions.
	b) Pure Abstract Classes( Interfaces )
		These are 'empty' classes where all functions are pure virtual and
		 hence you have to derive and then implement all of the functions.
		Pure virtual functions are actually functions which have no
		 implementation in base class and have to be implemented in derived class.
 * @link https://duygubulut.wordpress.com/tag/pure-virtual/
 * 
 * @note #include <bits/stdc++.h> library have all standard c++ libraries's libraries. :')
 * @link https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01541_source.html
 * 
 * @note Difference/Distinction between Abstract Class and Interface.
 * @link https://stackoverflow.com/questions/12854778/abstract-class-vs-interface-in-c#:~:text=An%20%22interface%22%20embodies%20the%20concept,specify%20the%20contract%20in%20isolation
 * @link https://www.stroustrup.com/bs_faq2.html#multiple
 * 
 * @note Interface created first in Java, in C++ we are using
 *  this style while Abstract Class.
 * @link https://en.wikipedia.org/wiki/Interface_(Java)
 * @return int 
 */
int	main()
{
	// IMateriaSource	*src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

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