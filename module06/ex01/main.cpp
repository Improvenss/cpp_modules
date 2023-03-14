/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:53:29 by gsever            #+#    #+#             */
/*   Updated: 2023/03/14 14:02:52 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Colors.hpp"

struct Data
{
	std::string	studentName;
	int			studentAge;
};

/**
 * @brief Data* to uintptr_t
 * 
 * It takes a pointer and converts it to the unsigned integer type uintptr_t.
 * @param ptr 
 * @return uintptr_t 
 */
uintptr_t	seralize( Data *ptr )
{

}

/**
 * @brief uintptr_t to Data*
 * 
 * It takes an unsigned integer parameter and converts it to a pointer to Data.
 * @param raw 
 * @return Data 
 */
Data	*deserialize( uintptr_t raw )
{

}

/**
 * @brief 
 * 
 * @return int 
 */
int	main()
{

}

/**
 * @brief en to tr PDF
 * 
	Aşağıdaki işlevleri uygulayın:

	uintptr_t serialize(Veri* ptr);
	Bir işaretçi alır ve onu uintptr_t işaretsiz tamsayı türüne dönüştürür.

	Data* deserialize(uintptr_t raw);
	İşaretsiz bir tamsayı parametresi alır ve onu Data işaretçisine dönüştürür.

	İşlevlerinizin beklendiği gibi çalıştığını test etmek için bir program yazın.

	Boş olmayan (veri üyeleri olduğu anlamına gelir) bir
	 Veri yapısı oluşturmalısınız.

	Data nesnesinin adresinde serialize() işlevini kullanın ve dönüş değerini
	 deserialize() işlevine iletin.
	Ardından, deserialize() dönüş değerinin orijinal işaretçiye
	 eşit olduğundan emin olun.

	Veri yapınızın dosyalarını teslim etmeyi unutmayın.
 * 
 */