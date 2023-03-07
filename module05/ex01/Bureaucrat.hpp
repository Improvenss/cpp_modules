/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:07:23 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 17:53:32 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Colors.hpp"
# include "Form.hpp"

class Form;

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
		void				decrementGrade( void );
		void				incrementGrade( void );
		void				signForm( Form &form );

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

std::ostream		&operator<<( std::ostream &os, const Bureaucrat &rhs );

#endif // BUREAUCRAT_HPP