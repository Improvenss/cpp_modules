/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:08 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 21:57:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	d1;
	DiamondTrap	d2("diamond2");
	DiamondTrap	d3("diamond3");

	std::cout << "-------- Players Created! ------"\
		<< std::flush << std::endl << std::endl;
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();
	std::cout << std::endl;
	d1.attack("diamond2");
	d2.takeDamage(d1.getDamage());
	std::cout << std::endl;
	d3.highFivesGuys();
	d2.guardGate();
	std::cout << std::endl;
	d1.attack("diamond2");
	d2.takeDamage(d1.getDamage());
	d2.beRepaired(500);
	std::cout << std::endl;
	std::cout << "\n-------- Players Destroying! ------"\
		<< std::flush << std::endl;
	return (0);
}