/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:08 by gsever            #+#    #+#             */
/*   Updated: 2023/02/26 15:51:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	s1;
	ScavTrap	s2("s2");
	// ScavTrap	s3("s3");
	// ScavTrap	s4(s2);
	// ScavTrap	s5 = s3;

	std::cout << "-------- Players Created! ------" << std::flush << std::endl << std::endl;
	// s1 = s2;
	// {
	// 	std::cout << "************** Scope Area *************" << std::flush << std::endl;
	// 	ClapTrap	*a = new ScavTrap();
	// 	ClapTrap	*b;
	// 	b = a;
	// 	delete	(b);
	// 	std::cout << "************** Scope Area Finished *************" << std::flush << std::endl;
	// }
	s1.attack("s2");
	s2.takeDamage(s1.getDamage());
	std::cout << std::endl;
	s1.ScavTrap::attack("s2");
	s2.takeDamage(s1.getDamage());
	std::cout << std::endl;
	s2.beRepaired(10);
	s2.guardGate();
	s1.attack("s2");
	s2.takeDamage(s1.getDamage());
	std::cout << std::endl;
	s1.ClapTrap::attack("s2");
	s2.takeDamage(s1.getDamage());
	std::cout << std::endl;
	std::cout << "-------- Players Destroying! ------" << std::flush << std::endl;
	return (0);
}