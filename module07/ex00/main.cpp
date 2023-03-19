/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:43:12 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 18:00:46 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template<typename ehe>
void	templateTests( ehe &lhs, ehe &rhs)
{
	std::cout << B_BLUE "------- Template Test Area ------------" END\
		<< std::flush << std::endl;
	std::cout << "lhs: " << lhs << std::flush << std::endl;
	std::cout << "rhs: " << rhs << std::flush << std::endl;
	std::cout << "min[lhs]: " << ::min(lhs, rhs) << std::flush << std::endl;
	std::cout << "max[rhs]: " << ::max(lhs, rhs) << std::flush << std::endl;
	::swap(lhs, rhs);
	std::cout << "Swapped." << std::flush << std::endl;
	std::cout << "lhs: " << lhs << std::flush << std::endl;
	std::cout << "rhs: " << rhs << std::flush << std::endl;
	std::cout << "min[lhs]: " << ::min(lhs, rhs) << std::flush << std::endl;
	std::cout << "max[rhs]: " << ::max(lhs, rhs) << std::flush << std::endl;
	std::cout << B_BLUE "---------------------------------------" END\
		<< std::flush << std::endl << std::endl;
}

int	main( void )
{
	// int area.
	int	a = 2;
	int	b = 3;

	templateTests(a, b);
	a = 2;
	b = 3;
	std::cout << "a = " << a << ", b = " << b << std::flush << std::endl;
	::swap(a, b);
	std::cout << "Swapped." << std::flush << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::flush << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::flush << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::flush << std::endl;
	std::cout << std::endl;

	// string area.
	std::string	c = "chaine1";
	std::string	d = "chaine2";

	templateTests(c, d);
	c = "chaine1";
	d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::flush << std::endl;
	::swap(c, d);
	std::cout << "Swapped." << std::flush << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::flush << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::flush << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::flush << std::endl;
	return (0);
}
/*
#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/