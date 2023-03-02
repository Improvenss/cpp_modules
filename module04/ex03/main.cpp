/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:20 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 17:24:25 by gsever           ###   ########.fr       */
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
# include "Character.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "AMateria.hpp"
# include "Colors.hpp"


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
 * 
 * @link https://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c
 * 
 * @return int 
 */
int	main()
{
	IMateriaSource	*src = new MateriaSource();// Created Materia book.
	src->learnMateria(new Ice());// Learned Ice formula.
	src->learnMateria(new Cure());// Learned Cure formula.

	ICharacter	*me = new Character("me");// Create myself in game.

	AMateria	*tmp;
	tmp = src->createMateria("ice");// Create "ice" Materia from Materia book while Ice formula.
	me->equip(tmp);// Equip created "ice" Materia to my [0],1,2,3 -> 0. spell/pocket.
	tmp = src->createMateria("cure");// Create "cure" Materia from Materia book while Cure formula.
	me->equip(tmp);// Equip created "cure" Materia to my 0,[1],2,3 -> 1. spell/pocket.

	ICharacter	*bob = new Character("bob");// Create a enemy. It's name is bob.

	me->use(0, *bob);// Use 0. index's spell to bob.
	me->use(1, *bob);// Use 1. index's spell to bob.

	// std::cout << B_GREEN "Leaks After: " << std::flush;
	// system("leaks InterfaceRecap | grep 'leaked bytes'");
	// std::cout << END << std::flush;
	delete bob;// Delete enemy.
	delete me;// Delete myself.
	delete src;// Delete Materia book.

	return (0);
}

/**
 * @brief PDF to Turkish language.
 * 
 * 
Materias beton sınıfları Ice and Cure'u uygulayın. Türlerini ayarlamak için adlarını küçük harflerle kullanın (Ice için "ice", Cure için "cure"). Elbette, üye işlevleri clone() aynı türden yeni bir örnek döndürür (yani, bir Ice Materia'yı klonlarsanız, yeni bir Ice Materia alırsınız).
use(ICacter&) üye işlevi şunu gösterecektir: • Buz: "* <ad>'a bir buz oku fırlatır *"
• Tedavi: "* <isim>'in yaralarını iyileştirir *"
<ad>, parametre olarak iletilen Karakterin adıdır. Açıyı yazdırma
parantezler (< ve >).
Aşağıdaki arabirimi uygulayacak olan somut karakter sınıfını yazın:


Bir Materia'yı diğerine atarken, yazı tipini kopyalamak
algı.

Karakter 4 yuvalık bir envantere sahiptir, bu da en fazla 4 Materia anlamına gelir. Envanter yapım aşamasında boştur. Materiaları buldukları ilk boş yuvaya yerleştirirler. Bu şu anlama gelir: 0. yuvadan 3. yuvaya. Dolu bir envantere bir Materia eklemeye veya var olmayan bir Materia'yı kullanmaya/çıkarmaya çalışırlarsa, hiçbir şey yapmayın (ancak yine de hatalar yasaktır). unequip() üye işlevi Materia'yı SİLMEMELİDİR!

Karakterinizin yerde bıraktığı Materia'ları istediğiniz gibi kullanın.
unequip() veya başka bir şeyi çağırmadan önce adresleri kaydedin, ancak
bellek sızıntılarından kaçınmanız gerektiğini unutmayın.

use(int, ICharacter&) üye işlevinin yuva[idx]'te Materia'yı kullanması ve hedef parametreyi AMeria::use işlevine iletmesi gerekir.

Karakterinizin envanteri her türde oyunu destekleyebilecektir.
Materyal.


Karakterinizin adını parametre olarak alan bir oluşturucusu olmalıdır. Bir Karakterin herhangi bir kopyası (kopya oluşturucu veya kopya atama işleci kullanılarak) derin olmalıdır. Kopyalama sırasında, bir Karakterin Materyalleri envantere yenileri eklenmeden önce silinmelidir. Elbette, bir Karakter yok edildiğinde Materyaller silinmelidir.
Aşağıdaki arabirimi uygulayacak somut sınıf MateriaSource'u yazın:

• LearnMateria(AMateria*)
Geçirilen Materia'yı parametre olarak kopyalar ve daha sonra klonlanabilmesi için bellekte saklar. Karakter gibi, MateriaSource da en fazla 4 Materia bilebilir. Benzersiz olmaları gerekmez.
• createMateria(std::string const &)
Yeni bir Materia döndürür. Sonuncusu, türü parametre olarak iletilen olana eşit olan MateriaSource tarafından daha önce öğrenilen Materia'nın bir kopyasıdır. Tür bilinmiyorsa 0 döndürür.

Özetle, MateriaSource'unuz gerektiğinde bunları oluşturmak için Materias "şablonlarını" öğrenebilmelidir. Ardından, yalnızca türünü tanımlayan bir dizi kullanarak yeni bir Materia oluşturabileceksiniz.

Her zamanki gibi, yukarıda verilenlerden daha fazla test uygulayın ve teslim edin.
 * 
 */