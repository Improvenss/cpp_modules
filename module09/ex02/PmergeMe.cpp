/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:46:11 by gsever            #+#    #+#             */
/*   Updated: 2023/04/19 23:43:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( int argc, char **argv )
{
	if (setArgsToArray(argc, argv) == EXIT_FAILURE)
		throw (std::invalid_argument("Invalid input value."));
}

PmergeMe::~PmergeMe( void ) {}

/* _________________________ MAIN FUCTION ___________________________________ */

void	PmergeMe::executePmergeSort( void )
{
	// You must be add sort func()'s here.
	// PmergeMe::timeTestFunction();
	this->printArrayAll("Before List: ", this->_arrayList);
	this->printArrayAll("Before Deque: ", this->_arrayDeque);
	// this->printArrayAll("std::list<int>: ", this->_arrayList);
	// this->printArrayAll("std::deque<int>: ", this->_arrayDeque);
	this->calcTimeWithClockFunc(TIME_START);
	this->sortMergeInsertAlgorithm(this->_arrayList);
	this->calcTimeWithClockFunc(TIME_END);

}
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

/**
 * @brief Trying set args numbers to this->_arrayList list.
 * 
 * @param argv 
 * @return int: error -1, ok 0.
 */
int	PmergeMe::setArgsToArray( int argc, char **argv )
{
	int	number;

	std::srand(std::time(NULL)); // Fill the containers with random numbers.
	for (int i = 1; i < argc; i++)
	{
		number = std::atoi(argv[i]);
		if (number <= 0)
		{
			std::cerr << B_RED "Error: [" << number\
				<< "] Just 'positive' integers." END\
				<< std::flush << std::endl;
			return (EXIT_FAILURE); // 1
		}
		this->_arrayList.push_back(number);
		this->_arrayDeque.push_back(number);
		// this->_arrayVector.push_back(number);
	}
	return (EXIT_SUCCESS); // 0
}
/* -------------------------------------------------------------------------- */
/* _________________________ TIME FUNCTIONS _________________________________ */

void	PmergeMe::calcTimeWithTimeFunc( int status )
{
	// double		timeDifference;

	if (status == TIME_START)
		std::time(&this->_timeTime);
	else if (status == TIME_END)
	{
		this->_timeDifference = std::difftime(\
			std::time(NULL), this->_timeTime);
		this->printTimeDifference("std::time(): ");
	}
}

/**
 * @brief Most sensitive way to measure for time(CPU).
 * 
	In C++98, the most sensitive way to measure the execution time of a function
	is by using the `clock()` function from the `<ctime>` header.
	This function measures the CPU time used by the program, which includes the
	time spent executing the function as well as any time spent in system calls
	or other operating system tasks.
 * 
 * @param status 
 */
void	PmergeMe::calcTimeWithClockFunc( int status )
{
	// std::cout << "clock -> " << std::clock() << std::flush << std::endl;
	if (status == TIME_START)
		this->_timeClock = std::clock();
	else if (status == TIME_END)
	{
		this->_timeDifference = static_cast<double>(\
			std::clock() - this->_timeClock) / CLOCKS_PER_SEC * 1000;
		this->printTimeDifference("std::clock(): ");
	}
}

void	PmergeMe::calcTimeWithGettimeofdayFunc( int status )
{
	struct timeval	ct; // ct -> curret time.
	if (status == TIME_START)
		gettimeofday(&this->_timeTimeval, NULL);
	else if (status == TIME_END)
	{
		gettimeofday(&ct, NULL);
		this->_timeDifference = static_cast<double>(
			ct.tv_usec - this->_timeTimeval.tv_usec);
		this->printTimeDifference("gettimeofday(): ");
	}
		// this->_timeDifference = static_cast<double>(
		// 	(this->_timeTimeval.tv_sec * 1000)
		// 	+ (this->_timeTimeval.tv_usec / 1000) - this->_timeTimeval.)
	// std::cout << "gettimeofday(): " << this->_timeTimeval.tv_usec\
	// 	<< std::flush << std::endl;
}

void	PmergeMe::timeTestFunction( void )
{
	calcTimeWithTimeFunc(TIME_START);
	calcTimeWithClockFunc(TIME_START);
	calcTimeWithGettimeofdayFunc(TIME_START);
	// for (long i = 0; i < 3000000000; i++); // 1 billion times = ~1 second
	for (long i = 0; i < 3000; i++); // 1 billion times ~1 second
	std::cout << "-----------" << std::flush << std::endl;
	calcTimeWithTimeFunc(TIME_END);
	calcTimeWithClockFunc(TIME_END);
	calcTimeWithGettimeofdayFunc(TIME_END);
}
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */
/* -------------------------------------------------------------------------- */
/* _________________________ SORTING FUNCTIONS ______________________________ */

/**
 * @brief 
 * 
Merge-insert sort is a combination of two sorting algorithms:
 merge sort and insertion sort.
The basic idea is to use merge sort on larger subarrays, and insertion
 sort on smaller subarrays.
This can result in a more efficient sorting algorithm because insertion
 sort is faster than merge sort for small inputs, and merge sort is
 faster than insertion sort for larger inputs.
 * 
 * @tparam T 
 * @param container 
 */
template<typename T>
void	PmergeMe::sortMergeInsertAlgorithm( T &container )
{
	// if ()
	(void)container;
}
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

/**
 * @brief We print the array type given as a parameter.
 * 
 * @tparam T 
 * @param message First print message.
 * @param container After array values.
 */
template<typename T>
void	PmergeMe::printArrayAll( std::string message, const T &container )
{
	typename T::const_iterator	it;

	std::cout << message << std::flush;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::flush << std::endl;
}

/**
 * @brief Your string after this->_timeDifference value printing.
 * 
 * @param string Your message.
 */
void	PmergeMe::printTimeDifference( std::string string )
{
	std::cout << string << this->_timeDifference << std::flush << std::endl;
}
/* -------------------------------------------------------------------------- */
/* _________________________ EXCEPTIONS _____________________________________ */
/* -------------------------------------------------------------------------- */