/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:51:48 by gsever            #+#    #+#             */
/*   Updated: 2023/03/01 19:52:01 by gsever           ###   ########.fr       */
/*                                                                        	*/
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		Character( std::string const &name );
		Character( Character const &rhs );
		~Character( void );

		Character			&operator=( Character const &rhs );

		std::string const	&getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );
};

#endif // CHARACTER_HPP