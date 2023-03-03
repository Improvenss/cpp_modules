/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:53:50 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 15:26:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Colors.hpp"
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal( void );
		Animal( std::string name );
		Animal( const Animal &rhs );
		virtual ~Animal( void );// Virtual ~Animal Destructor for Colon type can allowing to free.

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;// If animals dog or cat have same func(), not calling this func. Calling own self func().
		virtual Brain	&getBrain( void ) const = 0;
};

#endif // ANIMAL_HPP