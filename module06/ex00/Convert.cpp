/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/14 16:53:33 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

// Convert::Convert( void )
// {
// 	// std::cout << "Convert Default Constructor called."\
// 	// 	<< std::flush << std::endl;
// 	_c = '\0';
// 	_i = 0;
// 	_f = 0.0f;
// 	_d = 0.0;
// 	_type = NONE;
// 	_isPossible = true;
// }

// Convert::Convert( char *argv ) : _string(argv), _str(argv)
// {
// 	// std::cout << "Convert String and Str Constructor called: " << _string\
// 	// 	<< std::flush << std::endl;
// 	_c = '\0';
// 	_i = 0;
// 	_f = 0.0f;
// 	_d = 0.0;
// 	_type = NONE;
// 	_isPossible = true;
// }

// Convert::~Convert( void )
// {
// 	// std::cout << "Convert Destructor called."\
// 	// 	<< std::flush << std::endl;
// }

/*-------------------- MAIN FUNCTION --------------------*/
/**
 * @brief Main convert func().
 * 
 * Convert steps starting here.
 * 
 * @note static_cast operator:
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-static-cast-operator-c-only
 * 
 * @note reinterpret_cast operator:
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-reinterpret-cast-operator-c-only
 * 
 * @note const_cast operator:
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-const-cast-operator-c-only
 * 
 * @note dynamic_cast operator:
 * @link https://www.ibm.com/docs/bg/zos/2.2.0?topic=expressions-dynamic-cast-operator-c-only
 */
void	Convert::convertString( void )
{
	setType();
	if (getType() == 0) // If input not have a type. --> e_type -> NONE
		throw (Convert::NotHaveAnyType()); // print: RED Input's not have a type! END
	if (!isPossible())
		return ;
	switch (_type)
	{
		case CHAR:
			_c = _string[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
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
}

/*-------------- SET GET FUNCTIONS() --------------------*/
void	Convert::setString( std::string string ) { _string = string; }

std::string	Convert::getString( void ) { return (_str); }

char	Convert::getChar( void ) { return (_c); }

int	Convert::getInt( void ) { return (_i); }

float	Convert::getFloat( void ) { return (_f); }

double	Convert::getDouble( void ) { return (_d); }

void	Convert::setType( void )
{
	if (isChar())
		_type = CHAR;
	else if (isInt())
		_type = INT;
	else if (isFloat())
		_type = FLOAT;
	else if (isDouble())
		_type = DOUBLE;
	else if (isLiterals())
		_type = LITERALS;
	// std::cout << "the type: " << _type << std::flush << std::endl;
}

int	Convert::getType( void ) { return (_type); }
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

bool	Convert::isFloat( void )
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

bool	Convert::isDouble( void )
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

bool	Convert::isLiterals( void )
{
	if (!_isPossible
		|| (_string.compare("nan") == 0)
		|| (_string.compare("nanf") == 0)
		|| (_string.compare("+inff") == 0) // Float
		|| (_string.compare("-inff") == 0) // Float
		|| (_string.compare("+inf") == 0) // Double
		|| (_string.compare("-inf") == 0)) // Double
		return (true);
	return (false);
}
/*=-----------------------------------------------------=*/



void	Convert::printChar( void )
{
	if (isLiterals() || (!std::isprint( _i)
		&& (_i >= 127)))
		std::cout << "Impossible" << std::flush << std::endl;
	else if (!std::isprint(_i))
		std::cout << "Non displayable" << std::flush << std::endl;
	else
		std::cout << "'" << getChar() << "'" << std::flush << std::endl;
}

void	Convert::printInt( void )
{
	// if (isLiterals() || (!std::isprint(_i)
	// 	&& (_i >= 127)))
	if (isLiterals())
		std::cout << "Impossible" << std::flush << std::endl;
	else
		std::cout << getInt() << std::flush << std::endl;
}

void	Convert::printFloat( void )
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

void	Convert::printDouble( void )
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
	// os << "Input: " << rhs.getString() << std::flush << std::endl;
	os << "char: " << std::flush; rhs.printChar();
	os << "int: " << std::flush; rhs.printInt();
	os << "float: " << std::flush; rhs.printFloat();
	os << "double: " << std::flush; rhs.printDouble();
	// os << std::flush << std::endl;
	return (os);
}
