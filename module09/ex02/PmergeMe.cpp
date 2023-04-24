/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:46:11 by gsever            #+#    #+#             */
/*   Updated: 2023/04/24 11:17:15 by gsever           ###   ########.fr       */
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
	this->sortAlgorithmMergeInsert(this->_arrayList,\
		this->_arrayList.begin(), this->_arrayList.end());
	this->calcTimeWithClockFunc(TIME_END);

	this->calcTimeWithClockFunc(TIME_START);
	this->sortAlgorithmMergeInsert(this->_arrayDeque,\
		this->_arrayDeque.begin(), this->_arrayDeque.end());
	this->calcTimeWithClockFunc(TIME_END);

	this->printArrayAll("list: ", this->_arrayList);
	this->printArrayAll("deque: ", this->_arrayDeque);

	
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

template<typename T>
int	PmergeMe::ifArrayIsSorted( std::string string, T &container )
{
	typedef typename T::const_iterator	createIt;

	(void)string;
	(void)container;

	for (createIt it = container.begin(); it != container.end(); it++)
	{
		// if ()
	}
}
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
 * 
 * @fn T::begin(): 
 */
template<typename T>
void	PmergeMe::sortAlgorithmMergeInsert( T &container,
	typename T::iterator begin, typename T::iterator end )
{
	if (begin == end)
		return;

	typename T::difference_type	dist = std::distance(begin, end);
	typename T::iterator		mid = begin;
	std::advance(mid, dist / 2); // Setting iterator's middle.

	// std::cout << "begin -> " << *begin << std::flush << std::endl;
	// std::cout << "mid   -> " << *mid << std::flush << std::endl;
	// std::cout << "end   -> " << *end << std::flush << std::endl;
	// std::cout << "end 2 -> " << *(--(container.end())) << std::flush << std::endl;
	if (dist <= INSERTION_THRESHOLD)
	{
		// this->calcTimeWithClockFunc(TIME_START);
		this->sortAlgorithmInsertSort(container, begin, end);
		// this->calcTimeWithClockFunc(TIME_END);
	}
	else
	{
		// this->sortAlgorithmMergeSort(container, begin, mid);
		// this->sortAlgorithmMergeSort(container, mid, end);
		this->sortAlgorithmMergeInsert(container, begin, mid);
		this->sortAlgorithmMergeInsert(container, mid, end);
		this->sortAlgorithmMerge(container, begin, mid, end);
	}
}

template<typename T>
void	PmergeMe::sortAlgorithmInsertSort( T &container,
	typename T::iterator begin, typename T::iterator end )
{
	// std::cout << "Insert func() runned." << std::flush << std::endl;
	typedef typename T::iterator	createIt;
	typedef typename T::value_type	createType; // Creating type what type is this.

	// ./PmergeMe 94 5 23 2 4 8
	(void)container;
	(void)begin;
	(void)end;
	// for (createIt it = begin; it != end; it++)
	for (createIt it1 = ++container.begin(); it1 != container.end(); it1++)
	{
		createType	tmpNum = *it1;
		createIt	it2 = it1;
		std::cout << "*it1: " << *it1 << std::flush << std::endl;
		std::cout << "---------" << std::flush << std::endl;
		while (it2 != container.begin() && *(--it2) > tmpNum)
		{
			std::cout << "girdik" << std::flush << std::endl;
			createIt	itPrev = it2;
			createIt	itNext = itPrev;
			++itNext;
			*itNext = *itPrev;
		}
		createIt	itNext = it2;
		++itNext;
		*itNext = tmpNum;
	}
	this->printArrayAll("inside aq -> ", this->_arrayList);
}

template<typename T>
void	PmergeMe::sortAlgorithmMergeSort( T &container,
	typename T::iterator begin, typename T::iterator end )
{
	std::cout << "MergeSort func() runned." << std::flush << std::endl;
	(void)container;
	(void)begin;
	(void)end;
}

template<typename T>
void	PmergeMe::sortAlgorithmMerge( T &container, typename T::iterator begin,
	typename T::iterator mid, typename T::iterator end )
{
	T	leftArray;
	T	rightArray;
	(void)container;

	typedef typename T::iterator itCreate;

	// std::cout << "Merge func() runned." << std::flush << std::endl;
	// itCreate	i;
	for (itCreate i = begin; i != mid; i++)
		leftArray.push_back(*i);
	for (itCreate i = mid; i != end; i++)
		rightArray.push_back(*i);

	itCreate	i = leftArray.begin();
	itCreate	j = rightArray.begin();
	itCreate	k = begin;

	while (i != leftArray.end() && j != rightArray.end())
	{
		if (*i <= *j)
			*(k++) = *(i++);
		else 
			*(k++) = *(j++);
	}

	while (i != leftArray.end())
		*(k++) = *(i++);

	while (j != rightArray.end())
		*(k++) = *(j++);
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