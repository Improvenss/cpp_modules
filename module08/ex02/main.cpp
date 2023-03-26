/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:00:17 by gsever            #+#    #+#             */
/*   Updated: 2023/03/26 17:15:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	MutanStackSelfTest( void )
{
	std::cout << "********* MutantStack Area *********"\
		<< std::flush << std::endl;

	MutantStack<int>	mstack;

	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.push(5);
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.push(17);
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl << std::endl;

	std::cout << "mstack.top(): " << mstack.top()\
		<< std::flush << std::endl << std::endl;

	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	mstack.pop(); // Removes the top element.
	std::cout << "mstack.size(): " << mstack.size()\
		<< std::flush << std::endl << std::endl;

	// std::cout << mstack.size() << std::flush << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	std::cout << std::flush << std::endl;
	std::cout << "it: " << *it << std::flush << std::endl;
	++it;
	std::cout << "++it: " << *it << std::flush << std::endl;
	--it;
	std::cout << "--it: " << *it << std::flush << std::endl << std::endl;

	std::cout << "it = mstack.begin(): " << *mstack.begin()\
		<< std::flush << std::endl;
	std::cout << "ite = mstack.end(): " << *mstack.end()\
		<< std::flush << std::endl;
	std::cout << "while...  NOT: mstack.size(): " << mstack.size()\
		<< std::flush << std::endl;
	int	i = 0;
	while (it != ite)
	{
		std::cout << "i[" << i++ << "]: " << std::flush;
		std::cout << *it << std::flush << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
	std::cout << std::flush << std::endl;
	std::cout << "s.size(): " << s.size() << std::flush << std::endl;
	std::cout << "s.top(): " << s.top() << std::flush << std::endl;
	// std::cout << "s.begin(): " << s.begin() << std::flush << std::endl;
	// std::cout << "s.end(): " << s.end() << std::flush << std::endl;

	std::cout << "____________ List Area ____________"\
		<< std::flush << std::endl;

	std::list<int>	mList;

	mList.push_back(5);
	mList.push_back(17);

	std::cout << mList.back() << std::flush << std::endl;

	mList.pop_back();

	std::cout << mList.size() << std::flush << std::endl;

	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	// [...]
	mList.push_back(0);

	std::list<int>::iterator	listIt = mList.begin();
	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	std::list<int>::iterator	listIte = mList.end();
	std::cout << "listIte: " << *listIte << std::flush << std::endl << std::endl;

	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	++listIt;
	std::cout << "listIt: " << *listIt << std::flush << std::endl;
	--listIt;
	std::cout << "listIt: " << *listIt << std::flush << std::endl << std::endl;
	int	j = 0;
	while (listIt != listIte)
	{
		std::cout << "j[" << j++ << "]: " << std::flush;
		std::cout << *listIt << std::flush << std::endl;
		++listIt;
	}
	// std::list<int>::iterator	listBack = mList.back();
	// std::list<int>::iterator	listBack = mList.front();
	// j = 0;
	// while (listIt != listIte)
	// {
	// 	std::cout << "j[" << j++ << "]: " << std::flush;
	// 	std::cout << *listIt << std::flush << std::endl;
	// 	++listIt;
	// }
	std::list<int>	l(mList);
	std::cout << std::flush << std::endl;
	std::cout << "l.size(): " << l.size() << std::flush << std::endl;
	std::cout << "l.back(): " << l.back() << std::flush << std::endl;
	std::cout << "l.front(): " << l.front() << std::flush << std::endl;
	std::cout << "l.begin(): " << *l.begin() << std::flush << std::endl;
	std::cout << "l.end(): " << *l.end() << std::flush << std::endl;
}

void	MutantStackMendatoryTest( void )
{
	std::cout << "********* MutantStack Area *********"\
		<< std::flush << std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::flush << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::flush << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::flush << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << "____________ List Area ____________"\
		<< std::flush << std::endl;

	std::list<int>	mList;

	mList.push_back(5);
	mList.push_back(17);

	std::cout << mList.back() << std::flush << std::endl;

	mList.pop_back();

	std::cout << mList.size() << std::flush << std::endl;

	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	// [...]
	mList.push_back(0);

	std::list<int>::iterator	listIt = mList.begin();
	std::list<int>::iterator	listIte = mList.end();

	++listIt;
	--listIt;
	while (listIt != listIte)
	{
		std::cout << *listIt << std::flush << std::endl;
		++listIt;
	}
	std::list<int>	l(mList);
}

int	main()
{
	std::cout << B_BLUE "--------- Mendatory Test Area! -----------" END\
		<< std::flush << std::endl;
	MutantStackMendatoryTest();
	std::cout << B_BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
	std::cout << B_BLUE "------------- Self Test Area! ------------" END\
		<< std::flush << std::endl;
	MutanStackSelfTest();
	std::cout << B_BLUE "------------------------------------------" END\
		<< std::flush << std::endl;
	return (0);
}