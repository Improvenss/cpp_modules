/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:27 by gsever            #+#    #+#             */
/*   Updated: 2023/03/09 22:57:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert( void ) : _str(NULL)
{
	std::cout << "Convert Default Constructor called."\
		<< std::flush << std::endl;
}

Convert::Convert( const std::string string ) : _str(string)
{
	std::cout << "Convert String Constructor called: " << string\
		<< std::flush << std::endl;
}

Convert::~Convert( void )
{
	std::cout << "Convert Destructor called."\
		<< std::flush << std::endl;
}

void	Convert::setString( std::string string )
{
	this->_str = string;
}

std::string	Convert::getString( void )
{
	return (this->_str);
}