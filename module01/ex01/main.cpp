/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:02:20 by gsever            #+#    #+#             */
/*   Updated: 2022/12/28 20:44:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

void	phoneBook::initContact()
{
	phoneBook.userNumber
}

void	phoneBook::exitProgram()
{
	std::cout << "Program shutting down! See ya!" << std::endl;
	exit(0);
}

void	phoneBook::addContact()
{
	this->userNumber += 1;
	if (this->userNumber >= 9)
		this->userNumber = 1;
	std::cout << "ADDing new contact..." << std::endl;
	std::cout << "Name: ";
	std::cin >> users[userNumber].name;
	std::cout << "Surname: ";
	std::cin >> users[userNumber].lastName;
}

void	phoneBook::searchContact()
{
	int	chooseNum;

	chooseNum = 0;
	std::cout << "Showing user's name" << std::endl;
	std::cout << "Choose 0-8 user number";
	std::getline(std::cin, chooseNum);
	/// @brief //burada kaldik yaaaaww.
	std::cout << "name[" << this->users[userNumber].name << "]" << std::endl;
	std::cout << "last_name[" << this->users[userNumber].lastName << "]" << std::endl;
}

int	main()
{
	phoneBook	pBook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter your phoneBook command!\n ETC: ADD, SEARCH, EXIT\nCOMMAND:" << std::endl;
		std::cin >> input;
		std::cout << "inputun->[" << input << "]" << std::endl;
		if (!input.compare("EXIT"))
			pBook.exitProgram();
		else if (!input.compare("ADD"))
			pBook.addContact();
		else if (!input.compare("SEARCH"))
			pBook.searchContact();
		else
			std::cout << "You entered wrong command sir!" << std::endl;
	}
	return (0);
}