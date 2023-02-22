/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:58:30 by gsever            #+#    #+#             */
/*   Updated: 2023/02/22 17:42:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		bool	isGuardOn;

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &rhs );
		~ScavTrap( void );
		ScavTrap	&operator=( const ScavTrap &rhs );

		void			attack( const std::string &target );
		void			takeDamage( unsigned int amount );
		void			guardGate( void );
		unsigned int	getDamage( void );
};

#endif // SCAVTRAP_HPP