/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/16 18:27:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <iostream>

// ScalarConvert::ScalarConvert( void )
// {
// 	// std::cout << "ScalarConvert Default Constructor called."\
// 	// 	<< std::flush << std::endl;
// 	_c = '\0';
// 	_i = 0;
// 	_f = 0.0f;
// 	_d = 0.0;
// 	_type = NONE;
// 	_isPossible = true;
// }

// ScalarConvert::ScalarConvert( char *argv ) : _string(argv), _str(argv)
// {
// 	// std::cout << "ScalarConvert String and Str Constructor called: " << _string\
// 	// 	<< std::flush << std::endl;
// 	_c = '\0';
// 	_i = 0;
// 	_f = 0.0f;
// 	_d = 0.0;
// 	_type = NONE;
// 	_isPossible = true;
// }

// ScalarConvert::~ScalarConvert( void )
// {
// 	// std::cout << "ScalarConvert Destructor called."\
// 	// 	<< std::flush << std::endl;
// }

/**
 * @brief 
 * 
 * @note How can i initialize these static members?
 * @link https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
 */
std::string	ScalarConvert::_string = "";
char		*ScalarConvert::_str = NULL;
char		ScalarConvert::_c = '\0';
int			ScalarConvert::_i = 0;
float		ScalarConvert::_f = 0.0f;
double		ScalarConvert::_d = 0.0;
e_type		ScalarConvert::_type = NONE;
bool		ScalarConvert::_isPossible = true;


/*-------------------- MAIN FUNCTION --------------------*/
/**
 * @brief Main ScalarConvert func().
 * 
 * ScalarConvert steps starting here.
 * 
 * @note static_cast operator:
 * @link https://en.cppreference.com/w/cpp/language/static_cast
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-static-cast-operator-c-only
 * 
 * @note const_cast operator:
 * @link https://en.cppreference.com/w/cpp/language/const_cast
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-const-cast-operator-c-only
 * 
 * @note dynamic_cast operator:
 * @link https://en.cppreference.com/w/cpp/language/dynamic_cast
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-dynamic-cast-operator-c-only
 * 
 * @note reinterpret_cast operator:
 * @link https://en.cppreference.com/w/cpp/language/reinterpret_cast
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-reinterpret-cast-operator-c-only
 * 
 * @note -ERRORS-
 * @link https://www.reddit.com/r/learnprogramming/comments/5dckv2/c_undefined_symbols_for_architecture_x86_64/
 */
void	ScalarConvert::ScalarConvertString( char **argv )
{
	// setInit();
	setString(argv[1]);
	setType();
	if (getType() == 0) // If input not have a type. --> e_type -> NONE
		throw (ScalarConvert::NotHaveAnyType()); // print: RED Input's not have a type! END
	if (!isPossible())
		return ;
	// std::cout << "LINE: " << __LINE__ << std::flush << std::endl;
	switch (_type)
	{
		case CHAR:
			_c = _string[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			// ScalarConvert::_c = _string[0];
			// ScalarConvert::_i = static_cast<int>(_c);
			// ScalarConvert::_f = static_cast<float>(_c);
			// ScalarConvert::_d = static_cast<double>(_c);
			break;
		case INT:
			_i = std::stoi(_string);
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;
		case FLOAT:
			_f = std::stof(_string);
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
		case DOUBLE:
			_d = std::stod(_string);
			_c = static_cast<char>(_d);
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
		default:
			break;
	}
	stdOutConverted();
}

/*-------------- SET GET FUNCTIONS() --------------------*/
// void	ScalarConvert::setInit( void )
// {
// 	ScalarConvert::_string = "";
// 	ScalarConvert::_str = NULL;
// 	ScalarConvert::_c = '\0';
// 	ScalarConvert::_i = 0;
// 	ScalarConvert::_f = 0.0f;
// 	ScalarConvert::_d = 0.0;
// 	ScalarConvert::_type = NONE;
// 	ScalarConvert::_isPossible = true;
// }

void	ScalarConvert::setString( std::string string ) { _string = string; }

std::string	ScalarConvert::getString( void ) { return (_str); }

char	ScalarConvert::getChar( void ) { return (_c); }

int	ScalarConvert::getInt( void ) { return (_i); }

float	ScalarConvert::getFloat( void ) { return (_f); }

double	ScalarConvert::getDouble( void ) { return (_d); }

void	ScalarConvert::setType( void )
{
	if (isChar())
		_type = CHAR; // 1
	else if (isInt())
		_type = INT; // 2
	else if (isFloat())
		_type = FLOAT; // 3
	else if (isDouble())
		_type = DOUBLE; // 4
	else if (isLiterals())
		_type = LITERALS; // 5
	std::cout << "the type: " << _type << std::flush << std::endl;
}

int	ScalarConvert::getType( void ) { return (_type); }
/*=-----------------------------------------------------=*/

/*------------------ IS FUNCTIONS() ---------------------*/
/**
 * @brief Input can ScalarConvertable?
 * 
 * @return true 
 * @return false 
 */
bool	ScalarConvert::isPossible( void )
{
	try
	{
		if (_type == INT)
			_i = std::stoi(_string);
		else if (_type == FLOAT)
			_f = std::stof(_string);
	}
	catch(const std::exception& e)
	{
		_isPossible = false;
		return (false);
	}
	_isPossible = true;
	return (true);
}

bool	ScalarConvert::isChar( void )
{
	return (_string.length() == 1 && std::isalpha(_string[0])\
		&& std::isprint(_string[0]));
}

bool	ScalarConvert::isInt( void )
{
	// __SIZE_TYPE__	i;
	// size_t	i;
	int	i;

	i = 0;
	// while (_string[i] == '-' || _string[i] == '+')
	// 	i++;
	while (_string[i] == '-' || _string[i] == '+')
		i++;
	for (; i < (int)_string.length(); i++)
	{
		// std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
		if (!std::isdigit(_string[i]))
		{
			// std::cout << "false: " << _string[i] << std::flush << std::endl;
			return (false);
		}
	}
	
	// while (++i < (int)_string.length())
	// {
	// 	std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
	// 	// std::cout << "imiz -> i: " << i << " and " << std::isdigit(_string[i]) << std::flush << std::endl;
	// 	if (!std::isdigit(_string[i]))
	// 	{
	// 		std::cout << "false: " << _string[i] << std::flush << std::endl;
	// 		return (false);
	// 	}
	// }
	return (true);
}

bool	ScalarConvert::isFloat( void )
{
	int	i;
	int	found;

	if (_string.back() != 'f' // Last index need be 'f'.
		|| _string.find('.') == 0 // First index is '.'.
		|| _string.find('.') == std::string::npos // Last index is '.'.
		|| _string.find('.') == _string.length() - 2)
		return (false);
	i = 0;
	found = 0;
	while (_string[i] == '-' || _string[i] == '+')
		i++;
	for (; i < (int)_string.length() - 1; i++) // here length() - 1 for x.x[f] --> 'f'
	{
		if (_string[i] == '.')
			found++;
		// std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
		if ((!std::isdigit(_string[i]) && _string[i] != '.')
			|| found > 1)
		{
			// std::cout << "false: " << _string[i] << std::flush << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	ScalarConvert::isDouble( void )
{
	int	i;
	int	found;

	if (_string.find('.') == 0 // First index is '.'.
		|| _string.find('.') == std::string::npos // Last index is '.'.
		|| _string.find('.') == _string.length() - 1)
		return (false);
	i = 0;
	found = 0;
	while (_string[i] == '-' || _string[i] == '+')
		i++;
	for (; i < (int)_string.length(); i++)
	{
		if (_string[i] == '.')
			found++;
		// std::cout << "string[" << i << "]: " << _string[i] << std::flush << std::endl;
		if ((!std::isdigit(_string[i]) && _string[i] != '.')
			|| found > 1)
		{
			// std::cout << "false: " << _string[i] << std::flush << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	ScalarConvert::isLiterals( void )
{
	if (!_isPossible
		|| (_string.compare("nan") == 0)
		|| (_string.compare("nanf") == 0)
		|| (_string.compare("+inff") == 0) // Float
		|| (_string.compare("inff") == 0) // Float
		|| (_string.compare("-inff") == 0) // Float
		|| (_string.compare("+inf") == 0) // Double
		|| (_string.compare("inf") == 0) // Double
		|| (_string.compare("-inf") == 0)) // Double
		return (true);
	return (false);
}
/*=-----------------------------------------------------=*/



void	ScalarConvert::printChar( void )
{
	if (isLiterals() || (!std::isprint( _i)
		&& (_i >= 127)))
		std::cout << "Impossible" << std::flush << std::endl;
	else if (!std::isprint(_i))
		std::cout << "Non displayable" << std::flush << std::endl;
	else
		std::cout << "'" << getChar() << "'" << std::flush << std::endl;
}

void	ScalarConvert::printInt( void )
{
	// if (isLiterals() || (!std::isprint(_i)
	// 	&& (_i >= 127)))
	if (isLiterals())
		std::cout << "Impossible" << std::flush << std::endl;
	else
		std::cout << getInt() << std::flush << std::endl;
}

void	ScalarConvert::printFloat( void )
{
	if (_string.compare("nan") == 0
		|| _string.compare("nanf") == 0)
		std::cout << "nanf" << std::flush;
	else if (_string.compare("+inf") == 0
		|| _string.compare("+inff") == 0)
		std::cout << "+inff" << std::flush;
	else if (_string.compare("-inf") == 0
		|| _string.compare("-inff") == 0)
		std::cout << "-inff" << std::flush;
	else if (!_isPossible)
		std::cout << "Impossible" << std::flush;
	else
	{
		if (_f - static_cast<int>(_f) == 0)
			std::cout << _f << ".0f" << std::flush;
		else
			std::cout << getFloat() << "f" << std::flush;
	}
	std::cout << std::flush << std::endl;
}

void	ScalarConvert::printDouble( void )
{
	if (_string.compare("nan") == 0
		|| _string.compare("nanf") == 0)
		std::cout << "nan" << std::flush;
	else if (_string.compare("+inf") == 0
		|| _string.compare("+inff") == 0)
		std::cout << "+inf" << std::flush;
	else if (_string.compare("-inf") == 0
		|| _string.compare("-inff") == 0)
		std::cout << "-inf" << std::flush;
	else if (!_isPossible)
		std::cout << "Impossible" << std::flush;
	else
	{
		if (_d - static_cast<int>(_d) == 0)
			std::cout << _d << ".0" << std::flush;
		else
			std::cout << getDouble() << std::flush;
	}
	std::cout << std::flush << std::endl;
}

// const char	*ScalarConvert::NotHaveAnyType::what( void ) const throw()
// {
// 	return ("Input's not have any type!");
// }

// const char	*ScalarConvert::foo::what( void ) const throw()
// {
// 	return ("bar");
// }

void	ScalarConvert::stdOutConverted( void )
{
	// std::cout << "------------------------" << std::flush << std::endl;
	// std::cout << "Input: " << rhs.getString() << std::flush << std::endl;
	std::cout << "char: " << std::flush; ScalarConvert::printChar();
	std::cout << "int: " << std::flush; ScalarConvert::printInt();
	std::cout << "float: " << std::flush; ScalarConvert::printFloat();
	std::cout << "double: " << std::flush; ScalarConvert::printDouble();
	// std::cout << std::flush << std::endl;
}

// std::ostream	&operator<<( std::ostream &os, ScalarConvert &rhs )
// {
// 	// os << "------------------------" << std::flush << std::endl;
// 	// os << "Input: " << rhs.getString() << std::flush << std::endl;
// 	os << "char: " << std::flush; rhs.printChar();
// 	os << "int: " << std::flush; rhs.printInt();
// 	os << "float: " << std::flush; rhs.printFloat();
// 	os << "double: " << std::flush; rhs.printDouble();
// 	// os << std::flush << std::endl;
// 	return (os);
// }
