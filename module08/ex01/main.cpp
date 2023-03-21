/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:39:33 by gsever            #+#    #+#             */
/*   Updated: 2023/03/21 14:58:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	selfPartSpanTest2( void )
{
	std::cout << B_BLUE "------------- Self Test Area! ------------" END\
		<< std::flush << std::endl;
	try
	{
		std::list<int>	listSpan(10000); // Creating 10.000 number count(N) <int> list.
		Span::printList(&listSpan, "std::list<int>listSpan(10): ");

		std::srand(time(NULL)); // Creating numbers randomly.
		std::generate(listSpan.begin(), listSpan.end(), std::rand); // Generating list's begin to end random number.
		Span::printList(&listSpan, "std::list<int>listSpan(generate): ");

		Span	sp(listSpan.size()); // Creating Span class; have 10.000 number range.
		sp.printList(sp.getList(), "Span(sp): ");

		sp.addNumber(listSpan.begin(), listSpan.end()); // Adding these randomly created numbers in to the 'sp' class's list.
		sp.printList(sp.getList(), "Span(sp) addNumber(): ");

		std::cout << "selfSpan: shortestSpan: " << sp.shortestSpan()\
			<< std::flush << std::endl;
		std::cout << "selfSpan: longestSpan: " << sp.longestSpan()\
			<< std::flush << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << B_RED << e.what() << END << std::flush << std::endl;
	}
	std::cout << B_BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
}


void	selfPartSpanTest( void )
{
	std::cout << B_BLUE "------------- Self Test Area! ------------" END\
		<< std::flush << std::endl;
	try
	{
		std::list<int>	listSpan(10); // Creating 10 number count(N) <int> list.
		Span::printList(&listSpan, "std::list<int>listSpan(10): ");

		std::srand(time(NULL)); // Creating numbers randomly.
		std::generate(listSpan.begin(), listSpan.end(), std::rand); // Generating list's begin to end random number.
		Span::printList(&listSpan, "std::list<int>listSpan(generate): ");

		Span	sp(listSpan.size()); // Creating Span class; have 10 number range.
		sp.printList(sp.getList(), "Span(sp): ");

		sp.addNumber(listSpan.begin(), listSpan.end()); // Adding these randomly created numbers in to the 'sp' class's list.
		sp.printList(sp.getList(), "Span(sp) addNumber(): ");

		std::cout << "selfSpan: shortestSpan: " << sp.shortestSpan()\
			<< std::flush << std::endl;
		std::cout << "selfSpan: longestSpan: " << sp.longestSpan()\
			<< std::flush << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << B_RED << e.what() << END << std::flush << std::endl;
	}
	std::cout << B_BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
}

static void	mendatoryPartSpanTest( Span &sp )
{
	std::cout << B_BLUE "---------- Mendatory Test Area! ----------" END\
		<< std::flush << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// std::cout << "selfSpan: shortestSpan: " << sp.shortestSpan()\
	// 	<< std::flush << std::endl;
	// std::cout << "selfSpan: longestSpan: " << sp.longestSpan()\
	// 	<< std::flush << std::endl;
	Span::printList(sp.getList(), "");
	std::cout << sp.shortestSpan() << std::flush << std::endl;
	std::cout << sp.longestSpan() << std::flush << std::endl;
	std::cout << B_BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
}

int	main()
{
	Span	sp = Span(5);

	std::cout << "----------- Span List Created! -----------"\
		<< std::flush << std::endl;
	mendatoryPartSpanTest(sp);
	selfPartSpanTest();
	// selfPartSpanTest2();
	std::cout << "---------- Span List Destroying! ---------"\
		<< std::flush << std::endl;
	return (0);
}