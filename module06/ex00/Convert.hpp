/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/13 21:40:37 by gsever           ###   ########.fr       */
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
