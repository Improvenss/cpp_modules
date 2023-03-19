/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:20:13 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 16:21:58 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C( void ) { std::cout << "C Default Constructor called!"\
			<< std::flush << std::endl; };
		~C( void ) { std::cout << "C Destructor called!"\
			<< std::flush << std::endl; };
};

#endif // C_HPP