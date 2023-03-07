/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:51:53 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 00:11:50 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm Default Constructor called."\
		<< std::flush << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target)
	: Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Target Constructor called."\
		<< std::flush << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &rhs)
	: Form("RobotomyRequestForm", 72, 45), _target(rhs._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called."\
		<< std::flush << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm Destructor called."\
		<< std::flush << std::endl;
}

void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	if (this->getSigned() == false)
		throw (Form::FormNotSigned());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	static int	i; // Initializing = 0;
	if (++i % 2 == 0)
		std::cout << this->_target << " has been robotomized. :)"\
			<< std::flush << std::endl;
	else
		std::cout << this->_target << " robotomized failed. :/"\
			<< std::flush << std::endl;
}