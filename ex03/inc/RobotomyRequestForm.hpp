/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:38:34 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:39:37 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& form);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
	
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
	
		std::string getTarget() const;
		
		void execute(Bureaucrat const & executor) const;
};

#endif