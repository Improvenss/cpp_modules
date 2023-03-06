/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:08 by gsever            #+#    #+#             */
/*   Updated: 2023/03/06 19:04:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name ) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat Name Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, const int grade )
	: _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Name and Int Constructor called: " << this->_name\
		<< std::flush << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat( const Bureaucrat &rhs) : _name(rhs.getName()),
	_grade(rhs.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor called: " << this->_name\
		<< std::flush << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called: " << this->_name\
		<< std::flush << std::endl;
}

/**
 * @brief 
 * 
 * @link https://coding-examples.com/c/overloaded-assignment-operator-in-c/
 * @param rhs 
 * @return Bureaucrat& -> Copied class.
 */
Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &rhs )
{
	std::cout << "Bureaucrat Copy Assignment Operator Overload called: "\
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
// Bureaucrat	Bureaucrat::operator++( void )// Pre-increment -> ++Left
// {
// 	this->_grade++;
// 	return (*this);
// }

// Bureaucrat	Bureaucrat::operator++( int )// Post-increment -> Right++
// {
// 	Bureaucrat	tmp(*this);
// 	tmp._grade = this->_grade++;
// 	return (tmp);
// 	// return (Bureaucrat(this->_grade++));
// }

// Bureaucrat	Bureaucrat::operator--( void )// Pre-decrement -> --Left
// {
// 	this->_grade--;
// 	return (*this);
// }

// Bureaucrat	Bureaucrat::operator--( int )// Post-decrement -> Right--
// {
// 	Bureaucrat	tmp(*this);
// 	tmp._grade = this->_grade--;
// 	return (tmp);
// 	// return (Bureaucrat(this->_grade--));
// }
/*_______________________________________________________*/

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/**
 * @brief Top grade(like leaderboard) is 1,
 *  worst grade is 150.
 * 
 * We are downing grade( + ).
 */
void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

/**
 * @brief Top grade(like leaderboard) is 1,
 *  worst grade is 150.
 * 
 * We are raise grade( - ).
 */
void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too 'HIGH'.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
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
std::ostream	&operator<<( std::ostream &os, const Bureaucrat &rhs )
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}