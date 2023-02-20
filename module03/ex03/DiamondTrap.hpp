/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:31:25 by gsever            #+#    #+#             */
/*   Updated: 2023/02/20 22:03:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

// # include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &rhs );
		~DiamondTrap( void );
		DiamondTrap	&operator=( const DiamondTrap &rhs );

	void	attack( const std::string &target );
	void	whoAmI( void );
};

#endif // DIAMONDTRAP_HPP