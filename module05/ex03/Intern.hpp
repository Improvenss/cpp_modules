/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:31:35 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 01:07:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORM_ROBOTOMY		"robotomy request"
# define FORM_PRESIDENTIAL	"presidential pardon"
# define FORM_SHRUBBERY		"shrubbery creation"

class Intern
{
	public:
		Intern( void );
		Intern( const Intern& rhs );
		~Intern( void );

		Form	*makeForm( std::string name, std::string target );
};

#endif // INTERN_HPP