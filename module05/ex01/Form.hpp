/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:38:20 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 20:42:26 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include "Colors.hpp"

class Bureaucrat;

/**
 * @brief 
 * 
 * @param _signed: Represent form are signed or not signed.
 * @param _gradeToSign: Need minimum grade value for can sign the form.
 * @param _gradeToExecute: Need minimum grade value for can execute the form.
 */
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form( void );
		Form( const std::string name );
		Form( const std::string name, const int gradeToSign,
			const int gradeToExecute );
		Form( const Form &rhs );
		~Form( void );

		Form				&operator=( const Form &rhs );

		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute( void ) const;

		void				beSigned( const Bureaucrat &rhs );

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
	class FormAlreadySigned : public std::exception
	{
		public:
			// virtual const char*	what() const throw() { return ("Form already SIGNED!")}
			virtual const char*	what() const throw();
	};
	/*_______________________________________________________*/
};

std::ostream		&operator<<( std::ostream &os, const Form &rhs );

#endif // FORM_HPP