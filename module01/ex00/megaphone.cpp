/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:32:39 by gsever            #+#    #+#             */
/*   Updated: 2022/12/27 18:15:18 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>// Basic functions inside this library.
// using namespace std;

/**
 * @brief 
 * 
 * std::cout => standart->cout => standart->c_language_out(1);
 * 	Meaning, inside standart library's cout func().
 * std::endl => writing newline(\n)
 * 
 * toupper(int _c); -> Converting to upper with decimal value!.
 * 	If you don't write "type casting" -> (char) it's returning decimal value.
 * 	If you write type casting -> (char)toupper(int _c); -> returning char value.
 * 
 * @return int 
 */
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}