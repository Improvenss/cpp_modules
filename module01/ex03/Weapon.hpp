/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:27:38 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 16:53:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include "HumanA.hpp"
# include "HumanB.hpp"

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(/* args */);
	~Weapon();
	std::string	&getType( void ) const;
	void		setType( std::string type );
};

#endif