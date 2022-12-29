/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:22:11 by gsever            #+#    #+#             */
/*   Updated: 2022/12/29 18:37:09 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

/**
 * @brief 
 * 
	Constructor Types
	Default Constructor.
	Parameterized Constructor.
	Copy Constructor.
	Static Constructor.
	Private Constructor.
 * @link https://merttopuz.com/yazilim/oop/cpp-ile-oop-constructor
 * @link https://www.c-sharpcorner.com/blogs/what-is-constructor-and-its-type
 * 
 * @note Orthodox Canonical Class Form!
 * @link https://www.francescmm.com/orthodox-canonical-class-form/
 */
class Contact// Phone Book's contact.
{
	private:
		std::string	_name;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_dSecret;
		int			index;

		std::string	_getInput(std::string str) const;
		std::string	_getLimited(std::string str) const;
	public:
		Contact();
		~Contact();
		// void	initContact(Contact user);
		void	setContact(int	index);
		void	getContact(void) const;
		void	getUserInfo(void) const;
};

class PhoneBook
{
	private:
		Contact	users[8];
		// static int	userNumber;
	public:
		PhoneBook();
		~PhoneBook();
		void	addCommand(void);
		void	searchCommand(void) const;
		void	exitProgram(void) const;
};

#endif