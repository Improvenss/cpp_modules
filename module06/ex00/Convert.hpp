/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:21:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/09 23:26:41 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

// # define 

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
		std::string	_str;
	public:
		Convert( void );
		Convert( const std::string string );
		~Convert( void );

/*-------------- SET GET FUNCTIONS() ----------------------*/
		void		setString( std::string string );
		std::string	getString( void );
/*=-------------------------------------------------------=*/

};

#endif // CONVERT_HPP