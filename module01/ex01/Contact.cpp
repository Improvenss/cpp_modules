/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:22 by gsever            #+#    #+#             */
/*   Updated: 2022/12/30 13:11:10 by gsever           ###   ########.fr       */
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
	std::getline(std::cin, enteredInput);
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
	this->_index = index;
}

void	Contact::getContact(void) const
{
	if (this->_name.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << _index << std::flush;// std::flush -> bellege almadan direkt yazmani sagliyor.
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_getLimited(this->_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::getUserInfo(void) const
{
	std::cout << "User[" << _index << "] First Name: " << this->_name << std::flush << std::endl;
	std::cout << "User[" << _index << "] Last Name: " << this->_lastName << std::flush << std::endl;
	std::cout << "User[" << _index << "] Nickname: " << this->_nickName << std::flush << std::endl;
	std::cout << "User[" << _index << "] Phone Number: " << this->_phoneNumber << std::flush << std::endl;
	std::cout << "User[" << _index << "] Darkest Secret: " << this->_dSecret << std::flush << std::endl;
}