/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:56:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 01:27:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("Default"), _grade(150)
{
	std::cout << "Form Default Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Form::Form( const std::string name ) : _name(name), _grade(150)
{
	std::cout << "Form Name Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Form::Form( const std::string name, const int grade )
	: _name(name), _grade(grade)
{
	std::cout << "Form Name and Int Constructor called: " << this->_name\
		<< std::flush << std::endl;
	if (grade < 1)
		throw (Form::GradeTooHighException());
	else if (grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form( const Form &rhs) : _name(rhs.getName()),
	_grade(rhs.getGrade())
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
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

/*_____________INCREMENT/DECREMENT OPERATORS_____________*/
/*
	increment/decrement -> (artis/azalma)
	[pre-increment/pre-decrement] -> (ön artis/ön azalma)left(sol)
	[post-increment/post-decrement] -> (artis sonrasi/azalma sonrasi)right(sag)
*/
// Form	Form::operator++( void )// Pre-increment -> ++Left
// {
// 	this->_grade++;
// 	return (*this);
// }

// Form	Form::operator++( int )// Post-increment -> Right++
// {
// 	Form	tmp(*this);
// 	tmp._grade = this->_grade++;
// 	return (tmp);
// 	// return (Form(this->_grade++));
// }

// Form	Form::operator--( void )// Pre-decrement -> --Left
// {
// 	this->_grade--;
// 	return (*this);
// }

// Form	Form::operator--( int )// Post-decrement -> Right--
// {
// 	Form	tmp(*this);
// 	tmp._grade = this->_grade--;
// 	return (tmp);
// 	// return (Form(this->_grade--));
// }
/*_______________________________________________________*/

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getGrade( void ) const
{
	return (this->_grade);
}

/**
 * @brief Top grade(like leaderboard) is 1,
 *  worst grade is 150.
 * 
 * We are downing grade( + ).
 */
void	Form::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw (Form::GradeTooLowException());
	this->_grade++;
}

/**
 * @brief Top grade(like leaderboard) is 1,
 *  worst grade is 150.
 * 
 * We are raise grade( - ).
 */
void	Form::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw (Form::GradeTooHighException());
	this->_grade--;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too 'HIGH'.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too 'LOW'.");
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
	os << rhs.getName() << ", Form grade " << rhs.getGrade();
	return (os);
}