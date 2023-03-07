/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:39:52 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 01:31:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern Default Constructor called."\
		<< std::flush << std::endl;
}

Intern::Intern( const Intern &rhs )
{
	std::cout << "Intern Copy Constructor called."\
		<< std::flush << std::endl;
	*this = rhs;
}

Intern::~Intern( void )
{
	std::cout << "Intern Destructor called."\
		<< std::flush << std::endl;
}

Form	*Intern::makeForm( std::string name, std::string target )
{
	try
	{
		std::string	formNames[] = { FORM_SHRUBBERY,
			FORM_ROBOTOMY, FORM_PRESIDENTIAL };
		Form		*forms[] = { new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)};
		for (int i = 0; i < 3; i++)
		{
			if (name == formNames[i])
			{
				std::cout << "Intern creates " << name\
					<< std::flush << std::endl;
				return (forms[i]);
			}
		}
		throw (Intern::InternCantCreateFrom());
	}
	catch (const std::exception &e )
	{
		std::cerr << YELLOW << e.what() << END << std::flush << std::endl;
		return (nullptr);
	}
	// std::cout << "Intern can't create " << name << " form."\
	// 	<< std::flush << std::endl;
	// return (nullptr);
}

const char	*Intern::InternCantCreateFrom::what() const throw()
{
	return ("Intern can't create form.");
}