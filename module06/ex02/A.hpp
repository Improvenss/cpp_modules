/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:20:13 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 16:21:21 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
	public:
		A( void ) { std::cout << "A Default Constructor called!"\
			<< std::flush << std::endl; };
		~A( void ) { std::cout << "A Destructor called!"\
			<< std::flush << std::endl; };
};

#endif // A_HPP