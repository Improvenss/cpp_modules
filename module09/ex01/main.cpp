/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:34:46 by gsever            #+#    #+#             */
/*   Updated: 2023/04/15 20:37:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cerr << "You must be enter just one argument."\
			<< std::flush << std::endl;
		std::cerr << "Like -> ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""\
			<< std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		RPN	polishMath(argv[1]);
		polishMath.calculateArray();
	}
	catch(const std::exception& e)
	{
		std::cerr << "RPN: Error: " << e.what() << std::flush << std::endl;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief PDF en to tr.
 * 
Bu kısıtlamalara sahip bir program oluşturmalısınız:
• Programın adı RPN'dir.
• Programınız argüman olarak ters çevrilmiş bir Lehçe matematiksel ifade almalıdır.
• Bu işlemde kullanılan sayılar her zaman 10'dan küçük olacaktır.
• Programınız bu ifadeyi işlemeli ve ekranda doğru sonucu vermelidir.
standart çıktı.
• Programın yürütülmesi sırasında bir hata oluşursa, standart çıktıda bir hata mesajı görüntülenmelidir.
• Programınız şu belirteçlerle işlemleri gerçekleştirebilmelidir: "+ - / *".

Parantezleri veya ondalık sayıları yönetmenize gerek yoktur.

$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "(1 + 1)"
Error
$>

Uyarı: Bir önceki alıştırmada kullandığınız kap(lar)
burada yasak. Bu alıştırmayı doğrulamak için kullandığınız kapsayıcı(lar)
 bu modülün geri kalanı için kullanılamaz.
 * 
 */