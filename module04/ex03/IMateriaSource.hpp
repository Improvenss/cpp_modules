/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:50 by gsever            #+#    #+#             */
/*   Updated: 2023/03/01 20:06:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual				~IMateriaSource() {}
		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria	*createMateria( std::string const &type ) = 0;
};

#endif // IMATERIASOURCE_HPP