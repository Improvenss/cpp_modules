/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:54 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 16:21:20 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

/**
 * @brief Abstract Class
 * 
 * @fn getType(): Returns the materia's type.
 * @fn *clone(): Cloning AMateria class and return the copy.
 * 
 */
class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &rhs );
		virtual	~AMateria( void );

		std::string const	&getType() const; // Returns the materia type

		virtual AMateria	*clone() const = 0;
		virtual void		use( ICharacter &target );
};

#endif // AMATERIA_HPP