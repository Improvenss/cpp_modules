/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:56:50 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 17:58:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include "Colors.hpp"

template<typename T>
void	swap( T &lhs, T &rhs )
{
	T	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template< typename T>
T	min( T &lhs, T &rhs )
{
	// return (lhs < rhs ? lhs : rhs);
	if (lhs == rhs)
		return (rhs); // PDF want if 2 param are equal return second one.
	else if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

template< typename T>
T	max( T &lhs, T &rhs )
{
	// return (lhs > rhs ? lhs : rhs);
	if (lhs == rhs)
		return (rhs); // PDF want if 2 param are equal return second one.
	else if (lhs < rhs)
		return (rhs);
	else
		return (lhs);
}

#endif // WHATEVER_HPP