/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:06 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 15:14:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( Ice const &rhs );
		~Ice( void );

		Ice	&operator=( Ice const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif // ICE_HPP