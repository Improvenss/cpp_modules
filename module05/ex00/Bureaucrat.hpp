/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:23 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 14:07:42 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

/**
 * @brief Exception Class
 * 
 * @note Exception class's implement steps.
 * @link https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
 * @link https://www.modernescpp.com/index.php/c-core-guidelines-the-noexcept-specifier-and-operator#:~:text=throw()%20is%20equivalent%20to%20noexcept,be%20used%20for%20function%20overloading.
 * @link https://stackoverflow.com/questions/88573/should-i-use-an-exception-specifier-in-c
 * @link https://stackoverflow.com/questions/12833241/what-is-the-difference-between-c03-throw-specifier-and-c11-noexcept
 * @link http://www.gotw.ca/publications/mill22.htm
 * 
 * @note throw(): throw() is an exception specification that was used prior
 *  to C++11 to indicate that a function does not throw any exceptions.
 * For example, void bar() throw(); is equivalent to void bar() noexcept;.
 * However, throw() is now considered deprecated, and it's recommended
 *  to use noexcept instead.
 * 
 * @note In C++, throw() and noexcept are used to specify exception-related
 *  behavior of functions at compile-time.
 * throw() is a deprecated function specifier in C++03, which was replaced
 *  by the noexcept specifier in C++11.
 * It indicates that the function will not throw any exceptions.
 * This means that if an exception is thrown during the execution of
 *  the function, it will call std::unexpected() function, which will
 *  in turn call std::terminate() function to terminate the program.
 *  Here is an example of a function with throw() specifier:
 *  Like void myFunction() throw();
 * 
 * This function will not throw any exceptions. If an exception is thrown
 *  during the execution of the function, it will call std::unexpected()
 *  function, which will in turn call std::terminate() function to
 *  terminate the program.
 * noexcept specifier, on the other hand, indicates that the function will
 *  not throw any exceptions, and also enables certain optimizations
 *  by the compiler.
 * If an exception is thrown during the execution of a noexcept function,
 *  std::terminate() will be called.
 *  Here is an example of a function with noexcept specifier:
 *  Like void myFunction() noexcept;
 * 
 * This function will not throw any exceptions. If an exception is thrown
 *  during the execution of the function, std::terminate() will be called.
 * At compile-time, throw() and noexcept can be used to make decisions
 *  about how to handle exceptions.
 * For example, if a function is marked with noexcept, the compiler can
 *  optimize the code by eliminating exception handling code.
 * It's worth noting that noexcept is more powerful and safer than throw(),
 *  as it not only specifies that the function will not throw exceptions,
 *  but also enables compiler optimizations and provides more accurate
 *  information to the caller of the function about its
 *  exception handling behavior.
 * 
 * @note 
	void func1() noexcept;        // does not throw
	void func2() noexcept(true);  // does not throw
	void func3() throw();         // does not throw

	void func4() noexcept(false); // may throw
 * @link https://www.modernescpp.com/index.php/c-core-guidelines-the-noexcept-specifier-and-operator#:~:text=throw()%20is%20equivalent%20to%20noexcept,be%20used%20for%20function%20overloading.
 * @note 
	void foo() throw(); // guaranteed not to throw an exception
	void bar() throw(int); // may throw an exception of type int
	void baz() throw(...); // may throw an exception of some unspecified type
 * @link https://stackoverflow.com/questions/88573/should-i-use-an-exception-specifier-in-c
 * 
 * @param _name: A 'Bureaucrat's name.
 * @param _grade: 1(Highest) to 150(Lowest) possible grade range.
 */
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name );
		Bureaucrat( const std::string name, const int grade );
		Bureaucrat( const Bureaucrat &rhs );
		~Bureaucrat( void );

		Bureaucrat&			operator=( const Bureaucrat &rhs );

	/*____________ INCREMENT/DECREMENT OPERATORS ____________*/
		// Bureaucrat			operator++( void );// Prefix increment operator.
		// Bureaucrat			operator++( int );// Postfix increment operator.
		// Bureaucrat			operator--( void );// Prefix decrement operator.
		// Bureaucrat			operator--( int );// Postfix decrement operator.
	/*_______________________________________________________*/

		const std::string	getName( void ) const;
		int					getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );

	/*__________________ EXCEPTION CLASSES __________________*/
	class GradeTooHighException : public std::exception
	{
		public:
			// virtual const char*	what() const throw() { return ("Grade too 'HIGH'."); }
			// virtual const char*	what() const _NOEXCEPT; // -> This can use after C++11
			// virtual const char*	what() const noexcept; // -> This can use C++11. throw() = noexcept. NOTE: we need to use at the present time noexcept word.
			virtual const char*	what() const throw(); // -> This is removed after C++03, throw() meaning; not throwing any exceptions.
	};
	class GradeTooLowException : public std::exception
	{
		public:
			// virtual const char*	what() const throw() { return ("Grade too 'LOW'."); }
			virtual const char*	what() const throw();
	};
	/*_______________________________________________________*/
};

std::ostream		&operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif // BUREAUCRAT_HPP