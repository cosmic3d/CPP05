/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:38:52 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 16:15:13 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat): name(bureaucrat.name), grade(bureaucrat.grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name,  int grade) : name(name), grade(grade){
	std::cout << "Bureaucrat name and grade constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat){
	if (this != &bureaucrat)
	{
		this->grade = bureaucrat.grade;
	}
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

//Increment grade function

void Bureaucrat::incrementGrade()
{
	try{
		if (this->grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade--;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

//Decrement grade function

void Bureaucrat::decrementGrade()
{
	try{
		if (this->grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}