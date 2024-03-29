/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:43:48 by gsever            #+#    #+#             */
/*   Updated: 2023/05/02 15:40:05 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief 
 * 
 * @note "Function prototypes started but need merge-insert algorithm
 *  working merging recursivly. After < 32 a array size, go to insert sorting.
 *  After the sorting steps need merging..."
 * 
 * @note std::sort() explaining.
 * @link https://www.scaler.com/topics/sort-function-in-cpp/
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main( int argc, char **argv )
{
	try
	{
		if (argc <= 1)
			throw (PmergeMe::exceptionInvalidArgument(\
				"You must be enter ./PmergeMe 3 5 9 7 4"));
		PmergeMe	pmerge(argc, argv);
		pmerge.executePmergeSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "PmergeMe: Error: " << e.what() << END\
			<< std::flush << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief PDF en to tr
 * 
Bu kısıtlamalara sahip bir program oluşturmalısınız:

• [OK] Programın adı PmergeMe'dir.
• [OK] Programınız 'POZITIF' bir tamsayı dizisini bağımsız değişken olarak
 kullanabilmelidir.
• [OK] Programınız, 'POZITIF' tamsayı sırasını sıralamak için birleştirme-ekleme
 sıralama algoritması kullanmalıdır.
• [OK] Programın yürütülmesi sırasında bir hata oluşursa, standart çıktıda bir hata
 mesajı görüntülenmelidir.

Kodunuzda en az iki farklı kap kullanmalısınız.
bu alıştırmayı onaylayın. Programınız şu adreste işleyebilmelidir:
en az 3000 farklı tamsayı.

Algoritmanızı her kapsayıcı için uygulamanız şiddetle tavsiye edilir.
ve böylece genel bir işlev kullanmaktan kaçınmak için.

Burada, standart çıktıda satır satır görüntülemeniz gereken bilgilerle ilgili
 bazı ek yönergeler verilmiştir.
• [OK] İlk satırda açık bir metin ve ardından sıralanmamış 'POZITIF' tamsayı dizisini
 görüntülemeniz gerekir.
• [OK] Üçüncü satırda, 'POZITIF' tamsayı dizisini sıralamak için kullanılan ilk
 kapsayıcıyı belirterek, algoritmanız tarafından kullanılan zamanı gösteren açık
 bir metin göstermelisiniz.
• [OK] Son satırda, 'POZITIF' tamsayı dizisini sıralamak için kullanılan ikinci
 kapsayıcıyı belirterek, algoritmanız tarafından kullanılan zamanı gösteren açık
 bir metin göstermelisiniz.

Sıralamanızı gerçekleştirmek için kullanılan zamanın görüntülenme biçimi
 ücretsizdir ancak seçilen kesinlik, kullanılan iki kap arasındaki farkı net
 bir şekilde görmeye izin vermelidir.

$> ./PmergeMe 3 5 9 7 4 Before: 35974
After: 34579
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before:  141 79 526 321 [...]
After:   79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$>

Uyarı: Önceki alıştırmalarda kullandığınız kap(lar) burada yasak.

Yinelemelerle ilgili hataların yönetimi sizin takdirinize bırakılmıştır.
 * 
 */