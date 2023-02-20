/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:34:58 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 09:43:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

/**
 * @brief Main(mother) class.
 * 
 * 
 * Parameters	Public/Private/Protected Access Modifier
 * 
 * -Public-	Accessible from anywhere.
 * -Private-	Accessible for only one class.
 * -Protected-	Accessible for any particularly given class along with its
 *  derived class or child classes. (Inheritance)
 * @link https://www.programiz.com/cpp-programming/public-protected-private-inheritance#:~:text=public%2C%20protected%20and%20private%20inheritance%20in%20C%2B%2B&text=protected%20inheritance%20makes%20the%20public,private%20in%20the%20derived%20class.
*/
class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &rhs );
		~ClapTrap();
		ClapTrap		&operator=( const ClapTrap &rhs );

		// virtual void	attack( const std::string &target );
		void			attack( const std::string &target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		bool			isALive( void );
		void			setDamage( unsigned int amount );
		unsigned int	getDamage( void );
};

#endif