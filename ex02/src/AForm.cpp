/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:28:49 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:06:10 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

AForm::AForm() : name("A Form"), signedAForm(false), gradeToSign(150), gradeToExecute(150){
	std::cout << "A Form default constructor called" << std::endl;
}

AForm::AForm(const AForm& form): name(form.name), signedAForm(form.signedAForm), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute){
	std::cout << "A Form copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), signedAForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	std::cout << "A Form name and grade constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout << "A Form destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& form){
	if (this != &form)
	{
		this->signedAForm = form.signedAForm;
	}
	std::cout << "A Form copy assignment operator called" << std::endl;
	return *this;
}

std::string AForm::getName() const{
	return this->name;
}

bool AForm::getSignedAForm() const{
	return this->signedAForm;
}

int AForm::getGradeToSign() const{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const{
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
		if (bureaucrat.getGrade() > this->gradeToSign)
			throw AForm::GradeTooLowException();
		if (this->signedAForm)
			throw AForm::AFormAlreadySignedException();
		this->signedAForm = true;
}

//Override << operator
std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << "A Form name: " << form.getName() << std::endl;
	os << "A Form signed: " << form.getSignedAForm() << std::endl;
	os << "A Form grade to sign: " << form.getGradeToSign() << std::endl;
	os << "A Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}