/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:08:43 by gsever            #+#    #+#             */
/*   Updated: 2023/03/09 16:30:51 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main( int argc, char **argv )
{
	if (argc == 2)
	{
		
	}
	else
	{
		std::cout << "You must be entered just one arguman!"\
			<< std::flush << std::endl;
	}

	return (0);
}
/**
 * @brief After the run must be this output.
 * 
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
 */

/**
 * @brief 
 * 
 * en to tr PDF
Bir C++ hazır bilgisinin en yaygın biçimindeki dize temsilini parametre
 olarak alan bir program yazın.
Bu hazır bilgi şu skaler tiplerden birine ait olmalıdır:
 char, int, float veya double.
char parametreleri dışında sadece ondalık gösterim kullanılacaktır.
Karakter değişmezlerine örnekler: 'c', 'a', ...
İşleri basitleştirmek için lütfen görüntülenemeyen karakterlerin giriş
 olarak kullanılmaması gerektiğini unutmayın.
Karaktere dönüştürme görüntülenemiyorsa bilgilendirici bir mesaj yazdırır.
int hazır değerlerine örnekler: 0, -42, 42...
Kayan sabit değerlere örnekler: 0.0f, -4.2f, 4.2f...
Bu sözde değişmezleri de halletmelisiniz (biliyorsunuz, bilim için):
 -inff, +inff ve nanf.
Double değişmez örnekleri: 0.0, -4.2, 4.2...
Bu sözde değişmezleri de halletmelisiniz (bilirsiniz, eğlence için):
 -inf, +inf ve nan.

Önce parametre olarak iletilen hazır bilginin türünü algılamanız, onu
 dizeden gerçek türüne dönüştürmeniz, ardından onu açıkça diğer üç veri
 türüne dönüştürmeniz gerekir.
Son olarak, sonuçları aşağıda gösterildiği gibi görüntüleyin.
Bir dönüştürme anlamsızsa veya taşarsa, kullanıcıya tür dönüştürmenin
 imkansız olduğunu bildiren bir mesaj görüntüleyin.
Sayısal limitleri ve özel değerleri işlemek için ihtiyacınız olan
 tüm başlıkları ekleyin.
 * 
 */