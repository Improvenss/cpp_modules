/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/13 18:22:24 by gsever           ###   ########.fr       */
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

/*-------------------- MAIN FUNCTION --------------------*/
/**
 * @brief Main convert func().
 * 
 * Convert steps starting here.
 */
void	Convert::convertString( void )
{
	this->setType();
	if (this->getType() == 0) // If input not have a type. --> e_type -> NONE
		throw (Convert::NotHaveAnyType()); // print: RED Input's not have a type! END
	if (!this->isPossible())
		return ;
	switch (this->_type)
	{
		case CHAR:
			this->_c = this->_string[0];
			this->_i = static_cast<int>(this->_c);
			this->_f = static_cast<float>(this->_c);
			this->_d = static_cast<double>(this->_c);
			break;
		case INT:
			this->_i = std::stoi(this->_string);
			this->_c = static_cast<char>(this->_i);
			this->_f = static_cast<float>(this->_i);
			this->_d = static_cast<double>(this->_i);
			break;
		case FLOAT:
			this->_f = std::stof(this->_string);
			this->_c = static_cast<char>(this->_f);
			this->_i = static_cast<int>(this->_f);
			this->_d = static_cast<double>(this->_f);
		case DOUBLE:
			this->_d = std::stod(this->_string);
			this->_c = static_cast<char>(this->_d);
			this->_i = static_cast<int>(this->_d);
			this->_f = static_cast<float>(this->_d);
		default:
			break;
	}
}

/*-------------- SET GET FUNCTIONS() --------------------*/
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
	else if (this->isInt())
		this->_type = INT;
	else if (this->isFloat())
		this->_type = FLOAT;
	// else if (this->isDouble())
	// 	this->_type = DOUBLE;
	// else if (this->isLiterals())
	// 	this->_type = LITERALS;
	std::cout << "the type: " << this->_type << std::flush << std::endl;
}

int	Convert::getType( void ) { return (this->_type); }
/*=-----------------------------------------------------=*/

/*------------------ IS FUNCTIONS() ---------------------*/
/**
 * @brief Input can convertable?
 * 
 * @return true 
 * @return false 
 */
bool	Convert::isPossible( void )
{
	try
	{
		if (this->_type == INT)
			this->_i = std::stoi(this->_string);
		else if (this->_type == FLOAT)
			this->_f = std::stof(this->_string);
	}
	catch(const std::exception& e)
	{
		this->_isPossible = false;
		return (false);
	}
	this->_isPossible = true;
	return (true);
}

bool	Convert::isChar( void )
{
	return (_string.length() == 1 && std::isalpha(_string[0])\
		&& std::isprint(_string[0]));
}

bool	Convert::isInt( void )
{
	// __SIZE_TYPE__	i;
	// size_t	i;
	int	i;

	i = 0;
	// while (this->_string[i] == '-' || this->_string[i] == '+')
	// 	i++;
	while (this->_string[i] == '-' || this->_string[i] == '+')
		i++;
	for (; i < (int)_string.length(); i++)
	{
		// std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
		if (!std::isdigit(this->_string[i]))
		{
			// std::cout << "false: " << _string[i] << std::flush << std::endl;
			return (false);
		}
	}
	
	// while (++i < (int)this->_string.length())
	// {
	// 	std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
	// 	// std::cout << "imiz -> i: " << i << " and " << std::isdigit(_string[i]) << std::flush << std::endl;
	// 	if (!std::isdigit(this->_string[i]))
	// 	{
	// 		std::cout << "false: " << _string[i] << std::flush << std::endl;
	// 		return (false);
	// 	}
	// }
	return (true);
}

bool	Convert::isFloat( void )
{
	int	i;
	int	found;

	if (this->_string.back() != 'f' // Last index need be 'f'.
		|| this->_string.find('.') == 0 // First index is '.'.
		|| this->_string.find('.') == std::string::npos // Last index is '.'.
		|| this->_string.find('.') == this->_string.length() - 2)
		return (false);
	i = 0;
	found = 0;
	while (this->_string[i] == '-' || this->_string[i] == '+')
		i++;
	for (; i < (int)_string.length(); i++)
	{
		if (this->_string[i] == '.')
			found++;
		// std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
		if ((!std::isdigit(this->_string[i]) && this->_string[i] != '.')
			|| found > 1)
		{
			// std::cout << "false: " << _string[i] << std::flush << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	Convert::isLiterals( void ) const
{
	if (!this->_isPossible
		|| (this->_string.compare("nan") == 0)
		|| (this->_string.compare("nanf") == 0)
		|| (this->_string.compare("+inff") == 0) // Float
		|| (this->_string.compare("-inff") == 0) // Float
		|| (this->_string.compare("+inf") == 0) // Double
		|| (this->_string.compare("-inf") == 0)) // Double
		return (true);
	return (false);
}
/*=-----------------------------------------------------=*/



void	Convert::printChar( void )
{
	if (this->isLiterals() || (!std::isprint( this->_i)
		&& (this->_i >= 127)))
		std::cout << "Impossible" << std::flush << std::endl;
	else if (!std::isprint(this->_i))
		std::cout << "Non displayable" << std::flush << std::endl;
	else
		std::cout << "'" << this->getChar() << "'" << std::flush << std::endl;
}

void	Convert::printInt( void )
{
	if (this->isLiterals() || (!std::isprint(this->_i)
		&& (this->_i >= 127)))
		std::cout << "Impossible" << std::flush << std::endl;
	else
		std::cout << this->getInt() << std::flush << std::endl;
}

void	Convert::printFloat( void )
{
	
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
	os << "char: " << std::flush; rhs.printChar();
	os << "int: " << std::flush; rhs.printInt();
	// os << "float: " << rhs.getFloat() << std::flush << std::endl;
	// os << "double: " << rhs.getDouble() << std::flush << std::endl;
	// os << std::flush << std::endl;
	return (os);
}
