/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:28:49 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:06:10 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Form::Form() : name("Form"), signedForm(false), gradeToSign(150), gradeToExecute(150){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& form): name(form.name), signedForm(form.signedForm), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute){
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	std::cout << "Form name and grade constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& form){
	if (this != &form)
	{
		this->signedForm = form.signedForm;
	}
	std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

std::string Form::getName() const{
	return this->name;
}

bool Form::getSignedForm() const{
	return this->signedForm;
}

int Form::getGradeToSign() const{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const{
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat){
		if (bureaucrat.getGrade() > this->gradeToSign)
			throw Form::GradeTooLowException();
		if (this->signedForm)
			throw Form::FormAlreadySignedException();
		this->signedForm = true;
}

//Override << operator
std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form name: " << form.getName() << std::endl;
	os << "Form signed: " << form.getSignedForm() << std::endl;
	os << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}