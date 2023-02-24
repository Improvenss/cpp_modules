/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:04 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 19:32:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	JustSelfTestForAllocationLoop( void )
{
	const Animal	*_animals[3] = { new Animal(), new Dog(), new Cat() };
	for (int a = 0; a < 3; a++)
	{
		std::cout << B_RED "------------------------" END << std::flush\
			<< std::endl << std::endl;
		std::cout << B_GREEN "Leaks Before: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked'");
		std::cout << END << std::flush;
		delete _animals[a];
		std::cout << B_GREEN "Leaks After: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked'");
		std::cout << END << std::flush;
	}
}

static void	JustSelfTestForAllocation( void )
{
	std::cout << YELLOW "*********** Default Animal Test Area ***********" END\
		<< std::flush << std::endl;
	const Animal	*a1 = new Animal();
	std::cout << "~~~~~~~~~~~~~ Animal Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	delete a1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Animals Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Animal	*d1 = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Dog Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete d1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Dog Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Animal	*c1 = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Cat Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete c1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Cat Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Dog		*doge = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ doge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete doge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Doge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Cat		*catge = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ catge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete catge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- catge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl << std::endl;

	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain");
	std::cout << END << std::flush;

	std::cout << "Creating but not allocated memory area." GREEN\
		<< std::flush << std::endl;
	const Animal	*animal1 = NULL;
	const Dog		*dog1 = NULL;
	const Cat		*cat1 = NULL;
	const Brain		*brain1 = NULL;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	delete animal1;
	delete dog1;
	delete cat1;
	delete brain1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << END "Creating but not allocated memory area finished sir!."\
		<< std::flush << std::endl;
	std::cout << YELLOW "************************************************" END\
		<< std::flush << std::endl;
}

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
	// std::cout << GREEN "Leaks: ";
	std::cout << B_GREEN "Leaks: " << std::flush;// Eger buraya std::flush yazmazsam "Leaks: " 'i terminalde calistirdigimiz leaks'ten sonra yazdiyor ve bir isime yaramiyor... :)
	system("leaks AnimalBrain | grep 'leaked'");
	std::cout << END << std::flush;
	std::cout << GREEN "************************************************" END\
		<< std::flush << std::endl;

// This area for allocating memory for inherited classes.
	JustSelfTestForAllocation();

// This area for test all class with loop.
	std::cout << "[[[[[[[[[Loop Started!]]]]]]]]]]]" << std::flush << std::endl;
	JustSelfTestForAllocationLoop();
	return (0);
}