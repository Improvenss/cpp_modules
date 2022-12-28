/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:04:01 by gsever            #+#    #+#             */
/*   Updated: 2022/12/28 20:04:11 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class contact// Phone Book's contact.
{
	public:
		std::string	name;
		std::string	lastName;
};

class phoneBook
{
	private:
		contact	users[8];
		static int	userNumber;
	public:
		void	initContact(void);
		void	addContact(void);
		void	searchContact(void);
		void	exitProgram(void);
};

#endif