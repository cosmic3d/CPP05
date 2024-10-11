/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:47:06 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:39:18 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
	
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
	
		std::string getTarget() const;
		
		void execute(Bureaucrat const & executor) const;
};

#endif