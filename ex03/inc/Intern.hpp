/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:54 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:40:51 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	private:
		AForm	*createShrubberyCreationForm( const std::string& target ) const;
		AForm	*createRobotomyRequestForm( const std::string& target ) const;
		AForm	*createPresidentialPardonForm( const std::string& target ) const;
		AForm	*handleInvalidForm( const std::string& formName ) const;
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();

		Intern& operator=(const Intern& intern);

		AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif