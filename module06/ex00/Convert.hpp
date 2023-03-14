/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/14 16:26:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <math.h>
# include <cctype>
# include <limits>
# include "Colors.hpp"

// # define CHAR	1
// # define INT	2
// # define FLOAT	4
// # define DOUBLE	8

enum e_type
{
	NONE, CHAR, INT, FLOAT, DOUBLE, LITERALS
};

/**
 * @brief Default Class
 * 
 * @note CTYPE: (C-Style); C language's 'Type Cast' can't check compiler_time.
 *  It's checking run_time herewith in program can fail in runtime.
 * @note STATICCAST: static_cast<>: This cast checking by compiler.
 *  Herewith program can't fail in runtime.
 * @note 
 * @link https://stackoverflow.com/questions/1609163/what-is-the-difference-between-static-cast-and-c-style-casting
 * 
 * @note STATIC CLASS -> These answer answered by chatGPT. 14.03.2023
What are the necessary conditions for a c++ class to be a static class?

In C++, there is no special syntax or keyword to define a class as static.
Instead, a class can be considered a static class
 if it meets the following conditions:

All members are static: A static class should only contain static members,
 since non-static members would require an instance of the class to be created.

No instances can be created: Since a static class is never instantiated,
 it should not have any public constructors.
 It can have a private constructor or no constructor at all.

No inheritance: A static class cannot be inherited from, since it does not
 have any instances to inherit from.

Namespace scope: A static class should be defined at namespace scope,
 rather than as a member of another class.

Here is an example of a static class that meets these conditions:

namespace MyNamespace {
    class MyStaticClass {
    public:
        static int myStaticMethod() {
            return 42;
        }

        // Other static members...
    };

    // Define static members outside of the class definition
    int MyStaticClass::myStaticMethod() {
        return 42;
    }
}

In this example, MyStaticClass has only static members and cannot be instantiated.
It is defined at namespace scope and does not allow inheritance.
 */
class Convert
{
	private:
		std::string	_string;
		char		*_str;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		e_type		_type;
		bool		_isPossible;
	public:
		Convert( void );
		// Convert( const std::string string, char *argv );
		Convert( char *argv );
		~Convert( void );

	/*----------------- MAIN FUNCTION --------------------*/
		void		convertString( void );

	/*-------------- SET GET FUNCTIONS() --------------------*/
		void		setString( std::string string );
		std::string	getString( void );
		char		getChar( void );
		int			getInt( void );
		float		getFloat( void );
		double		getDouble( void );

		void		setType( void );
		int			getType( void );
	/*=-----------------------------------------------------=*/

	/*------------------ IS FUNCTIONS() ---------------------*/
		bool		isPossible( void );
		bool		isChar( void );
		bool		isInt( void );
		bool		isFloat( void );
		bool		isDouble( void );
		bool		isLiterals( void ) const;
	/*=-----------------------------------------------------=*/

	/*----------------- PRINT FUNCTIONS() -------------------*/
		void		printChar( void );
		void		printInt( void );
		void		printFloat( void );
		void		printDouble( void );
	/*=-----------------------------------------------------=*/

	/*__________________ EXCEPTION CLASSES __________________*/
		class NotHaveAnyType : public std::exception
		{
			public:
				// virtual const char*	what() const throw();
				virtual const char*	what() const throw()
					{ return ("Input's not have any type!"); }
		};
		// class foo : public std::exception
		// {
		// 	public:
		// 		virtual const char*	what() const throw();
		// };
	/*_______________________________________________________*/
};

std::ostream	&operator<<( std::ostream &os, Convert &rhs );

#endif // CONVERT_HPP
