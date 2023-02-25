/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:54 by gsever            #+#    #+#             */
/*   Updated: 2023/02/25 22:20:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

// class ICharacter;

class AMateria
{
	protected:

	public:
		AMateria( std::string const &type );
		//[...]
		std::string const	&getType() const; // Returns the materia type

		virtual AMateria	*clone() const = 0;
		virtual void		use( ICharacter &target );
};

#endif // AMATERIA_HPP