/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:32:03 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 15:36:43 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("default"){
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form), target(form.target){
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target){
	std::cout << "Shrubbery Creation Form name and target constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form){
	if (this != &form)
	{
		this->target = form.target;
	}
	std::cout << "Shrubbery Creation Form copy assignment operator called" << std::endl;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getSignedAForm())
		throw AForm::AFormNotSignedException();
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("File could not be opened");
	file << "        *" << std::endl;
  file << "       ***" << std::endl;
  file << "      *****" << std::endl;
  file << "     *******" << std::endl;
  file << "    *********" << std::endl;
  file << "       |||" << std::endl;
  file << "       |||" << std::endl;
	file.close();
}