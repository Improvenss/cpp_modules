/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:26:55 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 18:39:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author Görkem SEVER (gsever)
 * @brief This ex00 we are learning how it's working 'Exception's working.
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define ON true
#define OFF false

/**
 * @brief 
 * 
 * @note Repetition meaning.
 * @link https://www.cs.fsu.edu/~myers/c++/notes/control2.html#:~:text=Repetition%20statements%20are%20called%20loops,code%20mulitple%20times%20in%20succession.&text=The%20three%20loop%20structures%20in,do%2Dwhile%20loops
 * @link https://www.bbc.co.uk/bitesize/guides/zcg9kqt/revision/7#:~:text=Repetition%20in%20a%20program%20means,you%20achieve%20the%20correct%20outcome.
 * 
 * @note Exceptions meaning.
 * @link https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
 * @note Why Exceptions can't be std::string? -> Because std::string throw()ing too a exception.
 * @link https://stackoverflow.com/questions/63795948/why-does-exceptionwhat-not-return-a-stdstring
 * 
 * @note Better pointers/references.
 * @link https://www.bilgigunlugum.net/prog/cprog/2c_isaretci
 * @return int 
 */
int	main()
{
		std::cout << GREEN "************ Self Test Area *************" END\
			<< std::flush << std::endl;
	if (OFF)
	{
		Bureaucrat	b1;// Default grade 150.
		Bureaucrat	b2("Gorkem", 73);
		Bureaucrat	b3("Ahmet", 1);
		Form		f1;
		Form		f2("Form2");
		Form		f3("Form3", 73, 73);
		Form		f4(f2);

		std::cout << "-------- Bureaucrats and Forms Created! ------"\
			<< std::flush << std::endl << std::endl;

		std::cout << "f1: " << f1 << std::flush << std::endl;
		std::cout << "f2: " << f2 << std::flush << std::endl;
		std::cout << "f3: " << f3 << std::flush << std::endl;
		std::cout << "f4: " << f4 << std::flush << std::endl;

		std::cout << "-------- Bureaucrats and Forms Destroying! ------"\
			<< std::flush << std::endl;
	}
	std::cout << GREEN "*****************************************" END\
		<< std::flush << std::endl << std::endl;

	try
	{
		Bureaucrat	b2("Gorkem", 73);
		Bureaucrat	b3("BOSS", 1);
		Form		f1;
		Form		f2("Hire", 1, 1);

		std::cout << "-------- Bureaucrats and Froms Created! ------"\
			<< std::flush << std::endl << std::endl;

		std::cout << "b2: " << b2 << std::flush << std::endl;
		std::cout << "b3: " << b3 << std::flush << std::endl << std::endl;

		std::cout << "f1: " << f1 << std::flush << std::endl;
		b2.signForm(f1);

		std::cout << "f2: " << f2 << std::flush << std::endl;
		b2.signForm(f2);
		b3.signForm(f2);
		b2.signForm(f2);
		b3.signForm(f2);

		std::cout << "-------- Bureaucrats and Forms Destroying! ------"\
			<< std::flush << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	return (0);
}

/**
 * @brief en to tr PDF
 * 
İstisna sınıflarının şu şekilde tasarlanması gerekmediğini lütfen unutmayın:
Ortodoks Kanonik Formu. Ama diğer tüm sınıflar yapmak zorunda.

Ofisler, koridorlar, formlar ve bekleme kuyruklarından oluşan yapay bir kabus tasarlayalım. Kulağa eğlenceli mi geliyor? HAYIR? Çok kötü.
İlk olarak, bu geniş bürokratik makinedeki en küçük dişli ile başlayın: Bürokrat. Bir Bürokrat şunlara sahip olmalıdır:
• Sabit bir ad.
• Ve 1 (mümkün olan en yüksek not) ile 150 (mümkün olan en düşük not) arasında değişen bir not
seviye).
Geçersiz bir not kullanarak bir Bürokratı örneklendirmeye yönelik herhangi bir girişim bir istisna oluşturmalıdır:
ya bir Bureaucrat::GradeTooHighException ya da bir Bureaucrat::GradeTooLowException.


Bu özniteliklerin her ikisi için de alıcılar sağlayacaksınız: getName() ve getGrade(). Bürokrat notunu artırmak veya azaltmak için iki üye işlevi de uygulayın. Derece aralığın dışındaysa, her ikisi de oluşturucuyla aynı istisnaları atar.

Hatırlamak. 1. sınıf en yüksek ve 150 en düşük olduğu için,
3. dereceyi artırmak bürokrata 2. not vermelidir.

----------------------
Artık bürokratlarınız olduğuna göre, onlara yapacak bir şeyler verelim. Bir yığın form doldurmaktan daha iyi bir aktivite olabilir mi?

Ardından bir Form sınıfı oluşturalım. Şunlara sahiptir:
• Sabit bir ad.
• İmzalanıp imzalanmadığını gösteren bir boole (yapım aşamasında değil). • İmzalamak için gereken sabit bir not.
• Ve bunu gerçekleştirmek için gereken sabit not.
Tüm bu özellikler özeldir, korunmaz.

Formun notları, Bürokrat için geçerli olan aynı kuralları izler. Bu nedenle, bir form notu sınırların dışındaysa aşağıdaki istisnalar atılır: Form::GradeTooHighException ve Form::GradeTooLowException.

Daha önce olduğu gibi, tüm öznitelikler için alıcılar yazın ve tüm formun bilgilerini basan ekleme («) operatörünün aşırı yüklenmesi.
 */