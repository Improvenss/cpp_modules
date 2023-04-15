/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:34:59 by gsever            #+#    #+#             */
/*   Updated: 2023/04/15 20:40:50 by gsever           ###   ########.fr       */
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
				throw (std::invalid_argument("Unexpected character."));
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
				throw (std::invalid_argument("Invalid operator. You can use [+, -, /, *]."));
				// std::cerr << "Error" << std::flush << std::endl;
				// exit(EXIT_FAILURE);
				break;
			}
			if (this->_stack.size() != 1)
				throw (std::out_of_range("Calculate problem."));
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