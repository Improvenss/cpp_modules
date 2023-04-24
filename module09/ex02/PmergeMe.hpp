/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:44:27 by gsever            #+#    #+#             */
/*   Updated: 2023/04/24 11:07:59 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
// # include <vector>
# include <sys/time.h>
// # include <ctime>
// # include <vector>
# include "Colors.hpp"

# define TIME_START				0
# define TIME_END				1
# define INSERTION_THRESHOLD	32

/**
 * @brief 
 * 
 * PRIVATE:
 * @param _arrayList: First array.
 * @param _arrayDeque: Second array.
 * @param _arraySize: Array's number count.
 * @param _timeTime: For calculating time with std::time(NULL) function.
 * @param _timeClock: For calculating time with std::clock() function.
 * @param _timeTimeval: For calculating time with 'timeval' struct,
 *  for update time need gettimeofday(&_timeTimeval, NULL) function.
 * @param _timeDifference: Calculated 'difference time' value.
 * 
 * PUBLIC:
 * @fn executePmergeSort: After the 'Destructor' all execute steps in here.
 * 
 */
class PmergeMe
{
	private:
		std::list<int>	_arrayList;
		std::deque<int>	_arrayDeque;
		// std::vector<int>	_arrayVector;
		// int				_arraySize;
		std::time_t		_timeTime;
		std::clock_t	_timeClock;
		struct timeval	_timeTimeval;
		double			_timeDifference;
	public:
		PmergeMe( void ); // Default Constructor.
		PmergeMe( int argc, char **argv ); // Argument Constructor.
		~PmergeMe( void ); // Destructor.

/* _________________________ MAIN FUCTION ___________________________________ */

		void	executePmergeSort( void );
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

		int		setArgsToArray( int argc, char **argv );
/* -------------------------------------------------------------------------- */
/* _________________________ TIME FUNCTIONS _________________________________ */

		void	calcTimeWithTimeFunc( int status );
		void	calcTimeWithClockFunc( int status );
		void	calcTimeWithGettimeofdayFunc( int status );
		void	timeTestFunction( void );
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */

		template<typename T>
		int		ifArrayIsSorted( std::string string, T &container );
/* -------------------------------------------------------------------------- */
/* _________________________ SORTING FUNCTIONS ______________________________ */

		template<typename T>
		void	sortAlgorithmMergeInsert( T &container,
			typename T::iterator begin, typename T::iterator end );
		template<typename T>
		void	sortAlgorithmInsertSort( T &container,
			typename T::iterator begin, typename T::iterator end );
		template<typename T>
		void	sortAlgorithmMergeSort( T &container,
			typename T::iterator begin, typename T::iterator end );
		template<typename T>
		void	sortAlgorithmMerge( T &container,
			typename T::iterator begin,
			typename T::iterator mid,
			typename T::iterator end );
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

		// void	printArrayTopIterator( void );
		template<typename T>
		void	printArrayAll( std::string message, const T &container );
		void	printTimeDifference( std::string string );
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */
/* -------------------------------------------------------------------------- */
};

#endif // PMERGEME_HPP