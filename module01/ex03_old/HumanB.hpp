/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:56:11 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 17:06:02 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
private:
	Weapon		_weaponSelf;
	std::string	_name;
public:
	HumanB();
	~HumanB();
	void	attack( void );
};

#endif
