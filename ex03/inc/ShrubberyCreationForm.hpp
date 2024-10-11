/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:01:12 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:39:55 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
	
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
	
		std::string getTarget() const;
		
		void execute(Bureaucrat const & executor) const;
};

#endif