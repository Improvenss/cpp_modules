/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:54:50 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 22:55:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string target);
		PresidentialPardonForm( const PresidentialPardonForm &rhs );
		~PresidentialPardonForm( void );

		void	execute( const Bureaucrat &executor ) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP