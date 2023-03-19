/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 12:57:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

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
 * @brief Static Class
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
class ScalarConvert
{
	private: // static members.
		static std::string	_string;
		static char			*_str;
		static char			_c;
		static int			_i;
		static float		_f;
		static double		_d;
		static e_type		_type;
		static bool			_isPossible;
	public:
		// ScalarConvert( void );
		// ScalarConvert( const std::string string, char *argv );
		// ScalarConvert( char *argv );
		// ~ScalarConvert( void );

	/*----------------- MAIN FUNCTION -----------------------*/
		static void			ScalarConvertString( char **argv );

	/*-------------- SET GET FUNCTIONS() --------------------*/
		// static void			setInit( void );
		static void			setString( std::string string );
		static std::string	getString( void );
		static char			getChar( void );
		static int			getInt( void );
		static float		getFloat( void );
		static double		getDouble( void );

		static void			setType( void );
		static int			getType( void );
	/*=-----------------------------------------------------=*/

	/*------------------ IS FUNCTIONS() ---------------------*/
		static bool			isPossible( void );
		static bool			isChar( void );
		static bool			isInt( void );
		static bool			isFloat( void );
		static bool			isDouble( void );
		static bool			isLiterals( void );
	/*=-----------------------------------------------------=*/

	/*----------------- PRINT FUNCTIONS() -------------------*/
		static void			printChar( void );
		static void			printInt( void );
		static void			printFloat( void );
		static void			printDouble( void );
		static void			stdOutConverted( void );
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

// std::ostream	&operator<<( std::ostream &os, ScalarConvert &rhs );

#endif // SCALARCONVERT_HPP
