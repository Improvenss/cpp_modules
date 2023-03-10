/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:53:50 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 20:43:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// # include <iostream>
# include "AAnimal.hpp"
// # include "Colors.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Cat( void );
		// Cat( std::string name );
		// Cat( const Cat &rhs );
		~Cat( void );

	void	makeSound( void ) const;
};

#endif // CAT_HPP