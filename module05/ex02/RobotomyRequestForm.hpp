/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:51:36 by gsever            #+#    #+#             */
/*   Updated: 2023/03/08 00:05:19 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class Bureaucrat;

/**
 * @brief 
 * 
 * @param _target: Breaucrat.
 */
class RobotomyRequestForm : public Form
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string target);
		RobotomyRequestForm( const RobotomyRequestForm &rhs );
		~RobotomyRequestForm( void );

		void	execute( const Bureaucrat &executor ) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP