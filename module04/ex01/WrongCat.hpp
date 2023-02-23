/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:53:10 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 12:58:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

// # include <iostream>
# include "WrongAnimal.hpp"
// # include "Colors.hpp"

class WrongCat : public WrongAnimal
{
	// protected:
		// std::string type;
	public:
		WrongCat( void );
		// WrongCat( std::string name );
		// WrongCat( const WrongCat &rhs );
		~WrongCat( void );

	void	makeSound( void ) const;
};

#endif // WRONGCAT_HPP