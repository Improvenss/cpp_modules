/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:58:30 by gsever            #+#    #+#             */
/*   Updated: 2023/02/17 18:06:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		bool	isGuardOn;

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &rhs );
		ScavTrap &operator=( const ScavTrap &rhs );
		~ScavTrap( void );

		void			attack( const std::string &target );
		void			takeDamage( unsigned int amount );
		void			guardGate( void );
		unsigned int	getDamage( void );
};

#endif