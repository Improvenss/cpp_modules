/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:24:12 by gsever            #+#    #+#             */
/*   Updated: 2023/01/02 11:56:47 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief 
 * 
 * "&" will find its location,
 * "*" will find what value's there.
 * @return int 
 */
int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << 
}