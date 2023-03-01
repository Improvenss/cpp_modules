/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:17:13 by gsever            #+#    #+#             */
/*   Updated: 2023/03/01 20:01:56 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>

// class AMateria;

/**
 * @brief Interface
 * 
 * 
 * @fn 
 * 
 */
class ICharacter
{
	public:
		virtual						~ICharacter() {}
		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

#endif // ICHARACTER_HPP