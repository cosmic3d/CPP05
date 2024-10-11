/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:40:13 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 15:43:50 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default"){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : AForm(form), target(form.target){
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){
	std::cout << "RobotomyRequestForm name and target constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form){
	if (this != &form)
	{
		this->target = form.target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSignedAForm())
		throw AForm::AFormNotSignedException();
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl;
	std::cout << "Drilling noises" << std::endl << std::endl;

	static int i = 0;
	i++;
	if (i % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized" << std::endl;

}