/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:47:46 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 15:50:42 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default"){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : AForm(form), target(form.target){
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target){
	std::cout << "PresidentialPardonForm name and target constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form){
	if (this != &form)
	{
		this->target = form.target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSignedAForm())
		throw AForm::AFormNotSignedException();
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;

}