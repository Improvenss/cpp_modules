/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:30:52 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 12:39:43 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include "HumanB.hpp"


class HumanA
{
private:
	Weapon		&_weaponSelf;
	std::string	_name;
public:
	HumanA();
	~HumanA();
	void	attack( void );
};

#endif