/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:22 by gsever            #+#    #+#             */
/*   Updated: 2022/12/29 19:25:16 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	// std::cout << "Contact class's -Constructor-" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact class's -Destructor-" << std::endl;
}

std::string	Contact::_getInput(std::string str) const
{
	std::string	enteredInput;

	std::cout << str;
	std::cin >> enteredInput;
	return (enteredInput);
}

std::string	Contact::_getLimited(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	return (str);
}

void	Contact::setContact(int	index)
{
	this->_name = this->_getInput("Enter First Name: ");
	this->_lastName = this->_getInput("Enter Last Name: ");
	this->_nickName = this->_getInput("Enter Nickname: ");
	this->_phoneNumber = this->_getInput("Enter Phone Number: ");
	this->_dSecret = this->_getInput("Enter Darkest Secret: ");
	this->index = index;
}

void	Contact::getContact(void) const
{
	if (this->_name.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;// std::flush -> bellege almadan direkt yazmani sagliyor.
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::getUserInfo(void) const
{
	std::cout << "User[" << index << "] First Name: " << this->_name << std::flush << std::endl;
	std::cout << "User[" << index << "] Last Name: " << this->_lastName << std::flush << std::endl;
	std::cout << "User[" << index << "] Nickname: " << this->_nickName << std::flush << std::endl;
	std::cout << "User[" << index << "] Phone Number: " << this->_phoneNumber << std::flush << std::endl;
	std::cout << "User[" << index << "] Darkest Secret: " << this->_dSecret << std::flush << std::endl;
}