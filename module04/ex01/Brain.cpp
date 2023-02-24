/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:24:52 by gsever            #+#    #+#             */
/*   Updated: 2023/02/23 18:03:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Constructor called." << std::flush << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called." << std::flush << std::endl;
}