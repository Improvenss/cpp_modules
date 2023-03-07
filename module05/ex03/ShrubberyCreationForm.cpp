/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:30:37 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 23:10:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called."\
		<< std::flush << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Target Constructor called."\
		<< std::flush << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &rhs)
	: Form("ShrubberyCreationForm", 145, 137), _target(rhs._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called."\
		<< std::flush << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm Destructor called."\
		<< std::flush << std::endl;
}

/**
 * @brief 
 * 
 * @link https://ascii.co.uk/art/plants
 * @param executor 
 */
void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	if (this->getSigned() == false)
		throw (Form::FormNotSigned());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	std::ofstream	file(this->getName() + "_shrubbery");
	file << "                      ___" << std::endl;
	file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
	file << "             ,-'          __,,-- \\" << std::endl;
	file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
	file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
	file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
	file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
	file << "     (     ,-'                  `." << std::endl;
	file << "      `._,'     _   _             ;" << std::endl;
	file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
	file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
	file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
	file << "                \"Hb HH dF" << std::endl;
	file << "                 \"HbHHdF" << std::endl;
	file << "                  |HHHF" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  dHHHb" << std::endl;
	file << "                .dFd|bHb.               o" << std::endl;
	file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
	file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
	file << "##########################################" << std::endl;
	file.close();
}