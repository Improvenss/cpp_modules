/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:08 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 00:17:20 by gsever           ###   ########.fr       */
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

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned(*this);
		// std::cout << GREEN << *this << " signed " << form.getName()\
		// 	<< END << std::flush << std::endl;
		std::cout << GREEN << this->getName() << " signed "\
			<< form.getName() << END << std::flush << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << this->getName() << " couldn't sign "\
			<< form.getName() << " beause " << e.what() << '\n' << END;
	}
	
}

void	Bureaucrat::executeForm( const Form &form ) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->getName() << " executed "\
			<< form.getName() << END << std::flush << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << this->getName() << " couldn't executed "\
			<< form.getName() << " beause " << e.what() << '\n' << END;
	}
	
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade too 'HIGH'.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade too 'LOW'.");
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