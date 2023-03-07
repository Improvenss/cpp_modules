/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:56:46 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 00:22:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm Default Constructor called."\
		<< std::flush << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Target Constructor called."\
		<< std::flush << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &rhs)
	: Form("PresidentialPardonForm", 25, 5), _target(rhs._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called."\
		<< std::flush << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm Destructor called."\
		<< std::flush << std::endl;
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	if (this->getSigned() == false)
		throw (Form::FormNotSigned());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	std::cout << "Informs that " << this->_target\
		<< " has been pardoned by Zaphod Beeblebrox."\
		<< std::flush << std::endl;
}