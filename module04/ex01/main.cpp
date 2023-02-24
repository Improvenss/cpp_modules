/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:04 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 17:15:01 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
// This area for PDF's test.
	std::cout << GREEN "*********** Default Animal Test Area ************" END\
		<< std::flush << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	std::cout << "-------- Dog and Cat Created! ------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "\n-------- Animals Destroying! ------"\
		<< std::flush << std::endl;
	delete j;// Should not create leak
	delete i;
	std::cout << GREEN "Leaks: ";// surayaa bak leaks'tan sonra yaziyor saka gibi
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END;
	std::cout << GREEN "************************************************" END\
		<< std::flush << std::endl;
// This area for allocating memory for inherited classes.
	std::cout << YELLOW "*********** Default Animal Test Area ***********" END\
		<< std::flush << std::endl;
	const Animal	*a1 = new Animal();
	std::cout << "~~~~~~~~~~~~~ Animal Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	system("leaks AnimalBrain | grep 'leaked'");
	delete a1;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "-------- Animals Allocated Destroyed! ------"\
		<< std::flush << std::endl;
	const Animal	*d1 = new Dog();
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "~~~~~~~~~~~~~ Dog Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete d1;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "-------- Dog Allocated Destroyed! ------"\
		<< std::flush << std::endl;
	const Animal	*c1 = new Cat();
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "~~~~~~~~~~~~~ Cat Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete c1;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "-------- Cat Allocated Destroyed! ------"\
		<< std::flush << std::endl;
	const Dog		*doge = new Dog();
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "~~~~~~~~~~~~~ doge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete doge;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "-------- Doge Allocated Destroyed! ------"\
		<< std::flush << std::endl;
	const Cat		*catge = new Cat();
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "~~~~~~~~~~~~~ catge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete catge;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << "-------- catge Allocated Destroyed! ------"\
		<< std::flush << std::endl << std::endl;

	system("leaks AnimalBrain");

	std::cout << "Creating but not allocated memory area." GREEN\
		<< std::flush << std::endl;
	const Animal	*animal1 = NULL;
	const Dog		*dog1 = NULL;
	const Cat		*cat1 = NULL;
	const Brain		*brain1 = NULL;
	system("leaks AnimalBrain | grep 'leaked'");
	delete animal1;
	delete dog1;
	delete cat1;
	delete brain1;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END "Creating but not allocated memory area finished sir!."\
		<< std::flush << std::endl;
	std::cout << YELLOW "************************************************" END\
		<< std::flush << std::endl;
}