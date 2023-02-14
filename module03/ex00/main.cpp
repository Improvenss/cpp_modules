/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:08 by gsever            #+#    #+#             */
/*   Updated: 2023/02/14 22:47:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	p1;
	ClapTrap	p2("player2");
	ClapTrap	p3("player3");
	ClapTrap	p4(p2);
	ClapTrap	p5 = p3;

	p4 = p5;
	std::cout << "-------- Players created! ------" << std::flush << std::endl << std::endl;
	while (p1.isALive() && p2.isALive() && p3.isALive())
	{
		p1.attack("player2");
		p1.setDamage(5);
		p2.takeDamage(5);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	p1.beRepaired(10);
	std::cout << std::endl;
	p2.beRepaired(10);
	std::cout << std::endl;
	std::cout << "-------- Players Destroying! ------" << std::flush << std::endl;
	return (0);
}