/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:10:38 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 16:37:57 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * @brief Creating random A/B/C class.
 * 
 * @return Base* 
 */
Base	*generate( void )
{
	static int	randomNum;

	randomNum++;
	if (randomNum % 3 == 0)
		return (new A);
	else if (randomNum % 3 == 1)
		return (new B);
	else
		return (new C);
}

/**
 * @brief Casting with '*'.
 * 
 * @param p 
 */
void	identify( Base *p )
{
	if (dynamic_cast<A*>(p))
	std::cout << "identify: A[*]" << std::flush << std::endl;
	else if (dynamic_cast<B*>(p))
	std::cout << "identify: B[*]" << std::flush << std::endl;
	else if (dynamic_cast<C*>(p))
	std::cout << "identify: C[*]" << std::flush << std::endl;
	else
		std::cout << "unknown type: *" << std::flush << std::endl;
}

/**
 * @brief Casting with '&'.
 * 
 * @param p 
 */
void	identify( Base &p )
{
	// if (dynamic_cast<A&>(p))
	// 	std::cout << "A" << std::flush << std::endl;
	// else if (dynamic_cast<B&>(p))
	// 	std::cout << "B" << std::flush << std::endl;
	// else if (dynamic_cast<C&>(p))
	// 	std::cout << "C" << std::flush << std::endl;
	// else
	// 	std::cout << "unknown type: &" << std::flush << std::endl;
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "identify: A[&]" << std::flush << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "identify: B[&]" << std::flush << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "identify: C[&]" << std::flush << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}

int	main()
{
	Base	*b1 = generate();
	Base	*b2 = generate();
	Base	*b3 = generate();
	Base	*b4 = generate();

	std::cout << "------------ Classes Created! -----------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "b1* = " << std::flush; identify(b1);
	std::cout << "b1& = " << std::flush; identify(*b1);
	std::cout << std::flush << std::endl;

	std::cout << "b2* = " << std::flush; identify(b2);
	std::cout << "b2& = " << std::flush; identify(*b2);
	std::cout << std::flush << std::endl;

	std::cout << "b3* = " << std::flush; identify(b3);
	std::cout << "b3& = " << std::flush; identify(*b3);
	std::cout << std::flush << std::endl;

	std::cout << "b4* = " << std::flush; identify(b4);
	std::cout << "b4& = " << std::flush; identify(*b4);
	std::cout << std::flush << std::endl;
	std::cout << "------------ Classes Destroying! -----------"\
		<< std::flush << std::endl;

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	return (0);
}