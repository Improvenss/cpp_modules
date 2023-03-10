/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/10 16:04:29 by gsever           ###   ########.fr       */
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
	this->_type = 0;
	this->_isPossible = true;
}

// Convert::Convert( const std::string string, char *argv )
// 	: _string(string), _str(argv)
// {
// 	std::cout << "Convert String and Str Constructor called: " << string\
// 		<< std::flush << std::endl;
// }

Convert::Convert( char *argv ) : _string(argv), _str(argv)
{
	// std::cout << "Convert String and Str Constructor called: " << this->_string\
	// 	<< std::flush << std::endl;
	this->_c = '\0';
	this->_i = 0;
	this->_f = 0.0f;
	this->_d = 0.0;
	this->_type = 0;
	this->_isPossible = true;
}

Convert::~Convert( void )
{
	// std::cout << "Convert Destructor called."\
	// 	<< std::flush << std::endl;
}

/*-------------- SET GET FUNCTIONS() ----------------------*/
void	Convert::setString( std::string string ) { this->_string = string; }

void	Convert::setType( void )
{
	if (isChar())
		this->_type = CHAR;
}

std::string	Convert::getString( void ) { return (this->_str); }

char	Convert::getChar( void ) { return (this->_c); }

int	Convert::getInt( void ) { return (this->_i); }

float	Convert::getFloat( void ) { return (this->_f); }

double	Convert::getDouble( void ) { return (this->_d); }
/*=-------------------------------------------------------=*/

void	Convert::convertString( void )
{
	this->_isPossible = this->isPossible();
}

bool	Convert::isPossible( void )
{

}

bool	Convert::isChar( void )
{
	return (this->_string.length() == 1 && std::isalpha(this->_string[0])\
		&& std::isprint(this->_string[0]));
}

bool	Convert::isInt( void )
{
	
}

std::ostream	&operator<<( std::ostream &os, Convert &rhs )
{
	os << "------------------------" << std::flush << std::endl;
	os << "Input: " << rhs.getString() << std::flush << std::endl;
	os << "char: " << rhs.getChar() << std::flush << std::endl;
	// os << "int: " << rhs.getInt() << std::flush << std::endl;
	// os << "float: " << rhs.getFloat() << std::flush << std::endl;
	// os << "double: " << rhs.getDouble() << std::flush << std::endl;
	// os << std::flush << std::endl;
	return (os);
}
