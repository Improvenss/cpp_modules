/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SerializeR.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:54:14 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 14:08:53 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Colors.hpp"

struct Data
{
	std::string	studentName;
	int			studentAge;
};

// struct Data;

/**
 * @brief static class
 * 
 */
class Serializer
{
	public:
		// Serializer( void );
		// ~Serializer( void );

		static uintptr_t	serialize( Data *ptr );
		static Data*		deseralize( uintptr_t raw );
};

#endif // SERIALIZER_HPP