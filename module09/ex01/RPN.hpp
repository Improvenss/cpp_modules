/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:34:53 by gsever            #+#    #+#             */
/*   Updated: 2023/05/01 16:34:01 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
// # include <cctype>
# include <stack>
# include "Colors.hpp"

/**
 * @brief 
 * 
 * @param _stack:
 * @param _input:
 * @param _operator: Current std::string's index. (argv[1]'s index).
 * 
 */
class RPN
{
	private:
		std::stack<int>		_stack;
		std::string			_input;
		char				_operator;
	public:
		RPN( void ); // Default Costructor.
		RPN( char *argv ); // Arguman Constructor.
		~RPN( void ); // Destructor.

/* _________________________ MAIN FUCTION ___________________________________ */

		void	calculateArray( void );
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */
/* -------------------------------------------------------------------------- */
/* _________________________ CHECK FUNCTIONS ________________________________ */
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

		void	printArrayTopIterator( void );
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */

/* exception -> Invalid Argument */
	class exceptionInvalidArgument : public std::exception
	{
		private:
			std::string	_message;
		public:
			exceptionInvalidArgument( void );
			exceptionInvalidArgument( std::string string );
			~exceptionInvalidArgument() throw(); // err; fixed: exception specification of overriding function is more lax than base version
			virtual const char	*what() const throw();
	};
/* ------------------------- */
/* exception -> Out Of Range */
	class exceptionOutOfRange : public std::exception
	{
		private:
			std::string	_message;
		public:
			exceptionOutOfRange( void );
			exceptionOutOfRange( std::string string );
			~exceptionOutOfRange() throw(); // err; fixer: exception specification of overriding function is more lax than base version
			virtual const char	*what() const throw();
	};
/* ------------------------- */
/* -------------------------------------------------------------------------- */
};

#endif // RPN_HPP