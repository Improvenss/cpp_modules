/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:55:07 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 15:12:05 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( Cure const &rhs );
		~Cure( void );

		Cure	&operator=( Cure const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif // CURE_HPP