/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:08:43 by gsever            #+#    #+#             */
/*   Updated: 2023/04/04 11:51:38 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author Görkem SEVER (gsever)
 * @brief In this exercise we will learn 'How it's working type casting?'.
 * @link https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ScalarConvert.hpp"

/**
 * @brief Converting the given argument to all types.
 * 
 * @note 1.0 How can i convert (char*) type to (std::string) type.
 * @link https://www.techiedelight.com/convert-char-to-string-cpp/
 * 
 * @note 2.0 What is 'cast'?
 * @note 2.1 What is 'Type Casting'?
 * @link https://www.javatpoint.com/type-casting-in-cpp 
 * @link https://cplusplus.com/doc/oldtutorial/typecasting/
 * @note 2.2 What is difference between static_cast<> and (ctype) casting?
 * @link https://stackoverflow.com/questions/1609163/what-is-the-difference-between-static-cast-and-c-style-casting
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "You must be enter just one arguman!"\
			<< std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		// std::string	input = argv[1];
		// ScalarConvert	c(input, argv[1]);
		// ScalarConvert	c(argv[1]);
		// ScalarConvert	c;

		// std::cout << "-------- ScalarConvert class Created! ----------"\
		// 	<< std::flush << std::endl << std::endl;
		// c.setString(argv[1]);
		// c.ScalarConvert::convertString();
		ScalarConvert::ScalarConvertString(argv);
		// std::cout << c << std::flush << std::endl;
		// std::cout << "-------- ScalarConvert class Destroying! ----------"\
		// 	<< std::flush << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	return (EXIT_SUCCESS); // 0
}
/**
 * @brief 
 * 
 * en to tr PDF
"convert" yöntemini içerecek statik bir sınıf ScalarConverter yazın, en yaygın biçiminde bir C++ hazır bilgisinin dize temsilini parametre olarak alır. Bu hazır bilgi, aşağıdaki a skaler türlerinden birine ait olmalıdır:

• karakter
• int
• batmadan yüzmek
• çift

char parametreleri dışında sadece ondalık gösterim kullanılacaktır.
Karakter değişmezlerine örnekler: 'c', 'a', ...

İşleri basitleştirmek için lütfen görüntülenemeyen karakterlerin giriş olarak kullanılmaması gerektiğini unutmayın. Karaktere dönüştürme görüntülenemiyorsa bilgilendirici bir mesaj yazdırır.
int hazır değerlerine örnekler: 0, -42, 42...

Kayan sabit değerlere örnekler: 0.0f, -4.2f, 4.2f...
Bu sözde değişmezleri de halletmelisiniz (biliyorsunuz, bilim için): -inff, +inff ve nanf.

Double değişmez örnekleri: 0.0, -4.2, 4.2...
Bu sözde değişmezleri de halletmelisiniz (bilirsiniz, eğlence için): -inf, +inf ve nan.

Sınıfınızın beklendiği gibi çalıştığını test etmek için bir program yazın.
Önce parametre olarak iletilen hazır bilginin türünü algılamalı, onu dizeden gerçek türüne dönüştürmeli, ardından açıkça diğer üç veri türüne dönüştürmelisiniz. Son olarak, sonuçları aşağıda gösterildiği gibi görüntüleyin.
Bir dönüştürme anlamsızsa veya taşıyorsa, kullanıcıya tür dönüştürmenin imkansız olduğunu belirten bir mesaj gösterin. Sayısal sınırları ve özel değerleri işlemek için ihtiyacınız olan tüm başlıkları ekleyin.

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

 * 
 */
