/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:04 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 17:49:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << GREEN "*********** Default Animal Test Area ***********" END\
		<< std::flush << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	std::cout << "-------- Dog and Cat Created! ------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "\n-------- Animals Destroying! ------"\
		<< std::flush << std::endl;
	system("leaks AnimalBrain");
	std::cout << GREEN "oncesi j" END << std::endl;
	delete	j;// Should not create leak
	system("leaks AnimalBrain");
	std::cout << GREEN "sonratsi j" END << std::endl;
	std::cout << "oncesi i" << std::endl;
	delete	i;
	system("leaks AnimalBrain");
	std::cout << "sornrati i" << std::endl;
	std::cout << GREEN "****************************************" END\
		<< std::flush << std::endl;
	std::cout << YELLOW "*********** Default Animal Test Area ***********" END\
		<< std::flush << std::endl;
	// while ()
	std::cout << YELLOW "****************************************" END\
		<< std::flush << std::endl;
}