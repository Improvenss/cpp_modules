/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:53:50 by gsever            #+#    #+#             */
/*   Updated: 2023/02/27 13:31:05 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// # include <iostream>
# include "AAnimal.hpp"
// # include "Colors.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		// Dog( std::string name );
		// Dog( const Dog &rhs );
		~Dog( void );

	void	makeSound( void ) const;
};

#endif // DOG_HPP