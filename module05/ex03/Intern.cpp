/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:39:52 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 15:09:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// static void	checkLeaks( void )
// {
// 	std::cout << B_GREEN "Leaks: " << std::flush;
// 	system("leaks BureaucratIntern | grep 'leaked bytes'");
// 	std::cout << END << std::flush;
// }

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
		Form	*tmpForm = NULL;
		// std::string	formNames[] = { FORM_SHRUBBERY,
		// 	FORM_ROBOTOMY, FORM_PRESIDENTIAL };
		// Form		*forms[] = { new ShrubberyCreationForm(target),
		// 	new RobotomyRequestForm(target),
		// 	new PresidentialPardonForm(target)};
		_t_formList	forms[] = {
			{ FORM_SHRUBBERY, new ShrubberyCreationForm(target) },
			{ FORM_ROBOTOMY, new RobotomyRequestForm(target) },
			{ FORM_PRESIDENTIAL, new PresidentialPardonForm(target) },
			{ "", NULL }
		};
		for (int i = 0; i < 3; i++)
		{
			if (name == forms[i].name)
			{
				std::cout << B_BLUE "Intern creates " << name << END\
					<< std::flush << std::endl;
				tmpForm = forms[i].type;
				// return (forms[i].type);
			}
			else
				delete (forms[i].type);
		}
		if (tmpForm == NULL)
			throw (Intern::InternCantCreateFrom());
		return (tmpForm);
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