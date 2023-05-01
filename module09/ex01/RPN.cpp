/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:34:59 by gsever            #+#    #+#             */
/*   Updated: 2023/05/01 16:33:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN( char *argv ) : _input(argv) {}

RPN::~RPN( void ) {}

/* _________________________ MAIN FUCTION ___________________________________ */

void	RPN::calculateArray( void )
{
	for (std::string::iterator	it = this->_input.begin();
		it != this->_input.end(); it++)
	{
		// char	c = static_cast<char>(*it); // Converted iterator to char.
		this->_operator = static_cast<char>(*it); // Converted iterator to char.
		// std::cout << "reading: [" << c << "]" << std::flush << std::endl;
		// std::cout << "type: " << typeof(_operator).name() << std::flush << std::endl;
		if (std::isdigit(this->_operator))
			this->_stack.push(this->_operator - '0'); // Converted char to int and add to _stack.
		else if (!std::isspace(this->_operator)) // Checking if not isspace.
		{
			if (this->_stack.size() < 2)
				throw (RPN::exceptionInvalidArgument("Unexpected character."));
			// std::cout << "stack.top(): " << this->_stack.top() << std::flush << std::endl;
			int	rhsNumber = this->_stack.top();
			this->_stack.pop();
			int	lhsNumber = this->_stack.top();
			this->_stack.pop();
			switch (this->_operator)
			{
			case '+':
				this->_stack.push(lhsNumber + rhsNumber);
				break;
			case '-':
				this->_stack.push(lhsNumber - rhsNumber);
				break;
			case '/':
				this->_stack.push(lhsNumber / rhsNumber);
				break;
			case '*':
				this->_stack.push(lhsNumber * rhsNumber);
				break;
			default:
				// throw (std::invalid_argument("Invalid operator. You can use [+, -, /, *].")); // C++11 NOK
				throw (RPN::exceptionInvalidArgument(
					"Invalid operator. You can use [+, -, /, *].")); // Self exception :).
				// std::cerr << "Error" << std::flush << std::endl;
				// exit(EXIT_FAILURE);
				break;
			}
			if (this->_stack.size() != 1)
				throw (RPN::exceptionOutOfRange("Calculate problem."));
		}
	}
	std::cout << this->_stack.top() << std::flush << std::endl;
}
/* -------------------------------------------------------------------------- */

/* _________________________ PRINT FUCTIONS _________________________________ */

void	printArrayTopIterator( void )
{
}
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */

/**
 * @brief Self detailed exceptions.
 * 
 * @link https://stackoverflow.com/questions/29906737/how-to-correctly-implement-my-own-exception-handler-in-c
 * 
 * @return const char* 
 */

/* exception -> Invalid Argument */

RPN::exceptionInvalidArgument::exceptionInvalidArgument( void )
	: _message("Invalid argument.")
{
	// this->_message = "Invalid argument.";
}

RPN::exceptionInvalidArgument::exceptionInvalidArgument( std::string string )
	: _message(string)
{
	// this->_message = string;
}

RPN::exceptionInvalidArgument::~exceptionInvalidArgument( void ) throw() {}

const char	*RPN::exceptionInvalidArgument::what() const throw()
{
	// return ("Invalid argument found.");
	// return ("Invalid operator. You can use [+, -, /, *].");
	// std::stringstream	ss;

	// ss << this->_message;
	// return (ss.str().c_str());
	return (this->_message.c_str());
}
/* ------------------------- */

/* exception -> Out Of Range */

RPN::exceptionOutOfRange::exceptionOutOfRange( void )
	: _message("Out of range.") {}

RPN::exceptionOutOfRange::exceptionOutOfRange( std::string string )
	: _message(string) {}

RPN::exceptionOutOfRange::~exceptionOutOfRange( void ) throw() {}

const char	*RPN::exceptionOutOfRange::what() const throw()
{
	// return ("Calculate problem.");
	// std::stringstream	ss;

	// ss << this->_message;
	// return (ss.str().c_str());
	return (this->_message.c_str());
}
/* ------------------------- */
/* -------------------------------------------------------------------------- */