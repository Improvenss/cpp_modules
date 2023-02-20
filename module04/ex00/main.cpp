/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:04 by gsever            #+#    #+#             */
/*   Updated: 2023/02/21 00:03:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	std::cout << GREEN "*********** True Animal Area ***********" END\
		<< std::flush << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "-------- Animals Created! ------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "j's Type: " << j->getType() << " " << std::flush << std::endl;
	j->makeSound();
	std::cout << "i's Type: " << i->getType() << " " << std::flush << std::endl;
	i->makeSound();
	std::cout << "meta's Type: " << meta->getType() << " " << std::flush << std::endl;
	meta->makeSound();
	std::cout << "\n-------- Animals Destroying! ------"\
		<< std::flush << std::endl;
	delete	meta;
	delete	j;
	delete	i;
	std::cout << GREEN "****************************************" END\
		<< std::flush << std::endl;

	// std::cout << RED "*********** Wrong Animal Area ***********" END\
		// << std::flush << std::endl;
	// std::cout << RED "****************************************" END\
	// 	<< std::flush << std::endl;
}