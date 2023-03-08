/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:26:55 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 14:27:48 by gsever           ###   ########.fr       */
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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define ON true
#define OFF false

void	checkLeaks( void )
{
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks BureaucratForms | grep 'leaked bytes'");
	std::cout << END << std::flush;
}

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
		Bureaucrat				b1;// Default grade 150.
		Bureaucrat				b2("Gorkem", 73);
		Bureaucrat				b3("Ahmet", 1);
		ShrubberyCreationForm	f1("Shrubbery");
		// RobotomyRequestForm		f2("Robotomy");
		// PresidentialPardonForm	f3("Presidential");

		std::cout << "-------- Bureaucrats and Forms Created! ------"\
			<< std::flush << std::endl << std::endl;

		std::cout << "-------- Bureaucrats and Forms Destroying! ------"\
			<< std::flush << std::endl;
	}
	std::cout << GREEN "*****************************************" END\
		<< std::flush << std::endl << std::endl;

	try
	{
		Bureaucrat				b2("Gorkem", 73);
		Bureaucrat				b3("BOSS", 1);
		ShrubberyCreationForm	f1("Shrubbery");
		RobotomyRequestForm		f2("Robotomy");
		PresidentialPardonForm	f3("Presidential");

		std::cout << "-------- Bureaucrats and Froms Created! ------"\
			<< std::flush << std::endl << std::endl;

		std::cout << "b2: " << b2 << std::flush << std::endl;
		std::cout << "b3: " << b3 << std::flush << std::endl << std::endl;

		std::cout << "--------------- Form 1 ( Shrubbery ) ---------------"\
			<< std::flush << std::endl;
		b2.signForm(f1);
		b2.executeForm(f1);
		std::cout << "--------------- Form 2 ( Robotomy ) ---------------"\
			<< std::flush << std::endl;
		b2.signForm(f2);
		b2.executeForm(f2);
		b3.signForm(f2);
		b3.executeForm(f2);
		b3.executeForm(f2);
		b3.executeForm(f2);
		b3.executeForm(f2);
		std::cout << "--------------- Form 3 ( Presidential ) ---------------"\
			<< std::flush << std::endl;
		b2.signForm(f3);
		b2.executeForm(f3);
		b3.signForm(f3);
		b3.executeForm(f3);
		std::cout << std::endl\
			<< "-------- Bureaucrats and Forms Destroying! ------"\
			<< std::flush << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	return (0);
}