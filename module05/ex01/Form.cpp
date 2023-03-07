/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:56:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 20:39:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Default"), _signed(false),
	_gradeToSign(100), _gradeToExecute(100)
{
	std::cout << "Form Default Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Form::Form( const std::string name ) : _name(name), _signed(false),
	_gradeToSign(100), _gradeToExecute(100)
{
	std::cout << "Form Name Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Form::Form( const std::string name, const int gradeToSign,\
		const int gradeToExecute ) : _name(name), _signed(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Name and Int Constructor called: " << this->_name\
		<< std::flush << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooLowException());
}

Form::Form( const Form &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()),
	_gradeToSign(rhs.getGradeToSign()),
	_gradeToExecute(rhs.getGradeToExecute())
{
	std::cout << "Form Copy Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Form::~Form( void )
{
	std::cout << "Form Destructor called: " << this->_name\
		<< std::flush << std::endl;
}

/**
 * @brief 
 * 
 * @link https://coding-examples.com/c/overloaded-assignment-operator-in-c/
 * @param rhs 
 * @return Form& -> Copied class.
 */
Form	&Form::operator=( const Form &rhs )
{
	std::cout << "Form Copy Assignment Operator Overload called: "\
		<< this->_name << std::flush << std::endl;
	if (this != &rhs)// We are checking if 2 class are same class. a1 = a1 etc.
	{
		// *this = rhs;
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool	Form::getSigned( void ) const
{
	return (this->_signed);
}

int	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned( const Bureaucrat &rhs )
{
	if (rhs.getGrade() > this->getGradeToSign())
		throw (Form::GradeTooLowException());
	if (this->_signed == true)
		throw (Form::FormAlreadySigned());
	this->_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade too 'HIGH'.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade too 'LOW'.");
}

const char	*Form::FormAlreadySigned::what() const throw()
{
	return (YELLOW "Form already SIGNED!" END);
}

/**
 * @brief 
 * 
 * @link https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c
 * @param os: Output Stream
 * @param rhs Right Hand Side
 * @return std::ostream& 
 */
std::ostream	&operator<<( std::ostream &os, const Form &rhs )
{
	os << B_CYAN "____________ Form Information _______________"\
		<< std::flush << std::endl;
	os << "Name: " << rhs.getName() << std::flush << std::endl;
	os << "Is Signed?: " << rhs.getSigned() << std::flush << std::endl;
	os << "Grade To Sign: " << rhs.getGradeToSign() << std::flush << std::endl;
	os << "Grade To Execute: " << rhs.getGradeToExecute() << END\
		<< std::flush << std::endl;
	return (os);
}