/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:22:29 by gsever            #+#    #+#             */
/*   Updated: 2023/03/07 23:16:31 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream> // For ShrubberyCreationForm's ofstream->file

class Bureaucrat;

/**
 * @brief 
 * 
 * 
 * @link https://ascii.co.uk/art/plants
 * @param _target: Bureaucrat.
 */
class ShrubberyCreationForm : public Form
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string target);
		ShrubberyCreationForm( const ShrubberyCreationForm &rhs );
		~ShrubberyCreationForm( void );

		void	execute( const Bureaucrat &executor ) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP