/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:20:13 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 16:21:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B( void ) { std::cout << "B Default Constructor called!"\
			<< std::flush << std::endl; };
		~B( void ) { std::cout << "B Destructor called!"\
			<< std::flush << std::endl; };
};

#endif // B_HPP