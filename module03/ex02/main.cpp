/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:08 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 09:48:54 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	ClapTrap	c1;
	ScavTrap	s1("scav1");
	FragTrap	f1("frag1");

	std::cout << "-------- Players Created! ------" << std::flush << std::endl << std::endl;
	s1.attack("frag1");
	f1.takeDamage(s1.getDamage());
	std::cout << std::flush << std::endl;
	s1.guardGate();
	f1.attack("scav1");
	s1.takeDamage(f1.getDamage());
	std::cout << std::flush << std::endl;
	s1.beRepaired(50);
	std::cout << std::flush << std::endl;
	f1.highFivesGuys();
	std::cout << "\n-------- Players Destroying! ------" << std::flush << std::endl;
	return (0);
}