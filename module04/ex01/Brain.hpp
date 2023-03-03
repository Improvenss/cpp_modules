/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:03 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 15:02:35 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain( void );
		// Brain( std::string name );
		// Brain( const Brain &rhs );
		~Brain( void );

		Brain const			&operator=( Brain const &rhs );

		void				setIdea( int const &index, std::string const &idea );
		std::string const	&getIdea( int const &index) const;
};

#endif // BRAIN_HPP