/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:46:54 by gsever            #+#    #+#             */
/*   Updated: 2023/04/03 19:12:06 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief 
 * 
 * @note Standard Containers;
 * @link https://www.geeksforgeeks.org/containers-cpp-stl/
 * 
 * @note BTC API for csv database file.
 * @link https://pro.coinmarketcap.com/account
 * 
 * @note Directly download
 * @link https://api.blockchain.info/charts/market-price?format=csv
 * @link https://www.quora.com/Where-can-I-find-a-CSV-file-of-Bitcoin-price-data-by-date
 * @link https://www.quora.com/Where-can-I-get-historical-raw-data-on-Bitcoin-price-and-volume-across-different-exchanges
 * 
 * 
 */
int	main( int argc, char **argv )
{
	try
	{
		(void)argv;
		if (argc != 2)
			throw (std::invalid_argument("You must be enter just one arguman!"));
		if (argv)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

/**
 * @brief en to tr PDF.
 * 
Bu modüldeki her alıştırmayı gerçekleştirmek için standart kapların kullanılması zorunludur.

Bir konteyner bir kez kullanıldığında, onu modülün geri kalanı için kullanamazsınız.

Alıştırmaları yapmadan önce konunun tamamını okumanız tavsiye edilir.

Her egzersiz için en az bir kap kullanmalısınız.
iki kap kullanımını gerektiren egzersiz 02 istisnası.

Kaynak dosyalarınızı -Wall, -Wextra ve -Werror bayraklarıyla gerekli çıktıya derleyecek her program için bir Makefile göndermelisiniz.
C++ kullanmalısınız ve Makefile'ınız yeniden bağlanmamalıdır.
Makefile dosyanız en azından $(NAME), all, clean, fclean ve re kurallarını içermelidir.

---------------------

Belirli bir tarihte belirli miktarda bitcoin değerini veren bir program oluşturmalısınız.
Bu program, zaman içinde bitcoin fiyatını temsil edecek csv formatında bir veritabanı kullanmalıdır. Bu veri tabanı bu konu ile birlikte sağlanmaktadır.
Program, değerlendirmek üzere farklı fiyatları/tarihleri saklayan ikinci bir veri tabanını girdi olarak alacaktır.

Programınız şu kurallara uymalıdır:
• Programın adı btc'dir.
• Programınız argüman olarak bir dosya almalıdır.
• Bu dosyadaki her satır şu biçimi kullanmalıdır: "tarih | değer".
• Geçerli bir tarih her zaman şu formatta olacaktır: Yıl-Ay-Gün.
• Geçerli bir değer, kayan nokta veya 0 ile 1000 arasında pozitif bir tam sayı olmalıdır.

Bu alıştırmayı doğrulamak için kodunuzda en az bir kapsayıcı kullanmalısınız.
Olası hataları uygun bir hata mesajı ile ele almalısınız.

İşte bir input.txt dosyası örneği:
$> kafa girişi.txt
tarih | değer
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>

Programınız girdi dosyanızdaki değeri ve ilişkili tarihi kullanacaktır.

Programınız, standart çıktıda, veri tabanınızda belirtilen tarihe göre değerin döviz kuru ile çarpılması sonucunu göstermelidir.

Aşağıda programın kullanımına bir örnek verilmiştir.

$> ./btc
Hata: dosya açılamadı.
$> ./btc girdi.txt
2011-01-03 => 3 = 0,9
2011-01-03 => 2 = 0,6
2011-01-03 => 1 = 0,3
2011-01-03 => 1,2 = 0,36
2011-01-09 => 1 = 0,32
Hata: pozitif bir sayı değil.
Hata: hatalı giriş => 2001-42-42
2012-01-11 => 1 = 7.1
Hata: çok büyük bir sayı.
$>

Uyarı: Bu alıştırmayı doğrulamak için kullandığınız kap(lar) artık bu modülün geri kalanında kullanılamayacaktır.
 * 
 */