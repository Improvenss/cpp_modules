/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:53:29 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 14:03:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void	checkLeaks( void )
{
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks Serialization | grep 'leaked bytes'");
	std::cout << END << std::flush;
}

/**
 * @brief 
 * 
 * @return int 
 */
int	main()
{
	// Serializer	serializ; // We can't create because this 'Serializer' class are static class.
	Data		*data = new Data;
	uintptr_t	raw;
	Data		*ptr;

	data->studentName = "Gorkem";
	data->studentAge = 22;

	raw = Serializer::serialize(data);
	std::cout << "data Seralize: " << raw << std::flush << std::endl;
	ptr = Serializer::deseralize(raw);
	std::cout << "data Deseralize: " << ptr\
		<< std::flush << std::endl << std::endl;

	raw = Serializer::serialize(data);
	std::cout << "data Seralize: " << raw << std::flush << std::endl;
	ptr = Serializer::deseralize(raw);
	std::cout << "data Deseralize: " << ptr\
		<< std::flush << std::endl << std::endl;

	std::cout << "Deserialized Name: " << ptr->studentName\
		<< std::flush << std::endl;
	std::cout << "Deserialized Age: " << ptr->studentAge\
		<< std::flush << std::endl;
	// checkLeaks();
	delete data;
	// delete ptr;
	checkLeaks();
	return (0);
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