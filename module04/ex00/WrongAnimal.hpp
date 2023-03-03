/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:34 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 12:54:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "Colors.hpp"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal( std::string name );
		WrongAnimal( const WrongAnimal &rhs );
		virtual ~WrongAnimal( void );// Virtual ~WrongAnimal Destructor for Colon type can allowing to free.

		std::string		getType( void ) const;
		void	makeSound( void ) const;// If WrongAnimals dog or cat have same func(), not calling this func. Calling own self func().
};

#endif // WRONGANIMAL_HPP