/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:53:50 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 23:50:12 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// # include <iostream>
# include "Animal.hpp"
// # include "Colors.hpp"

class Dog : public Animal
{
	// protected:
		// std::string type;
	public:
		Dog( void );
		// Dog( std::string name );
		// Dog( const Dog &rhs );
		~Dog( void );

	void	makeSound( void ) const;
};

#endif // DOG_HPP