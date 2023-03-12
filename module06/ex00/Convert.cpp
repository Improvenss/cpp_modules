/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/12 20:28:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert( void ) : _str(NULL)
{
	// std::cout << "Convert Default Constructor called."\
	// 	<< std::flush << std::endl;
	this->_c = '\0';
	this->_i = 0;
	this->_f = 0.0f;
	this->_d = 0.0;
	this->_type = NONE;
	this->_isPossible = true;
}

Convert::Convert( char *argv ) : _string(argv), _str(argv)
{
	// std::cout << "Convert String and Str Constructor called: " << this->_string\
	// 	<< std::flush << std::endl;
	this->_c = '\0';
	this->_i = 0;
	this->_f = 0.0f;
	this->_d = 0.0;
	this->_type = NONE;
	this->_isPossible = true;
}

Convert::~Convert( void )
{
	// std::cout << "Convert Destructor called."\
	// 	<< std::flush << std::endl;
}

/*-------------- SET GET FUNCTIONS() ----------------------*/
void	Convert::setString( std::string string ) { this->_string = string; }

std::string	Convert::getString( void ) { return (this->_str); }

char	Convert::getChar( void ) { return (this->_c); }

int	Convert::getInt( void ) { return (this->_i); }

float	Convert::getFloat( void ) { return (this->_f); }

double	Convert::getDouble( void ) { return (this->_d); }

void	Convert::setType( void )
{
	if (this->isChar())
		this->_type = CHAR;
	std::cout << "the type: " << this->_type << std::flush << std::endl;
}

int	Convert::getType( void ) { return (this->_type); }
/*=-------------------------------------------------------=*/

/**
 * @brief Main convert func().
 * 
 * Convert steps starting here.
 */
void	Convert::convertString( void )
{
	this->setType();
	if (this->getType() == 0) // If input not have a type. --> e_type -> NONE
		throw (Convert::NotHaveAnyType());
	// this->_isPossible = this->isPossible();
}

bool	Convert::isPossible( void )
{
	return (true);
}

bool	Convert::isChar( void )
{
	return (_string.length() == 1 && std::isalpha(_string[0])\
		&& std::isprint(_string[0]));
}

bool	Convert::isInt( void )
{
	return (true);
}

// const char	*Convert::NotHaveAnyType::what( void ) const throw()
// {
// 	return ("Input's not have any type!");
// }

// const char	*Convert::foo::what( void ) const throw()
// {
// 	return ("bar");
// }

std::ostream	&operator<<( std::ostream &os, Convert &rhs )
{
	// os << "------------------------" << std::flush << std::endl;
	os << "Input: " << rhs.getString() << std::flush << std::endl;
	os << "char: " << rhs.getChar() << std::flush << std::endl;
	// os << "int: " << rhs.getInt() << std::flush << std::endl;
	// os << "float: " << rhs.getFloat() << std::flush << std::endl;
	// os << "double: " << rhs.getDouble() << std::flush << std::endl;
	// os << std::flush << std::endl;
	return (os);
}
