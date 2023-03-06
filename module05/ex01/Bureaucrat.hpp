/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:23 by gsever            #+#    #+#             */
/*   Updated: 2023/03/06 22:58:14 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

/**
 * @brief Exception Class
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

		Bureaucrat			&operator=( const Bureaucrat &rhs );

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
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			// virtual const char*	what() const throw() { return ("Grade too 'LOW'."); }
			virtual const char*	what() const throw();
	};
	/*_______________________________________________________*/
};

std::ostream		&operator<<( std::ostream &lhs, const Bureaucrat &rhs );

#endif // BUREAUCRAT_HPP