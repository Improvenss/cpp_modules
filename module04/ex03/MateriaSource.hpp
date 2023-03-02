/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:22:29 by gsever            #+#    #+#             */
/*   Updated: 2023/03/02 16:02:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &rhs );
		~MateriaSource( void );

		MateriaSource	&operator=( MateriaSource const &rhs );

		void		learnMateria( AMateria* );
		AMateria	*createMateria( std::string const &type );
		AMateria	*getMateria( std::string const &type );
};

#endif // MATERIASOURCE_HPP