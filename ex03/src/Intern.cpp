/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:21:43 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:32:53 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other){
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other){
	if (this != &other)
	{
		(void)other;
	}
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

AForm *Intern::createShrubberyCreationForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::handleInvalidForm(const std::string& formName) const
{
	std::cout << "Form " << formName << " is not valid" << std::endl;
	return NULL;
}

AForm	*Intern::makeForm( const std::string& formName, const std::string& target ) const
{
	unsigned int	i;
	std::string		parameter[ 4 ] = { target, target, target, formName };
	std::string		forms[ 3 ] = { "shrubbery creation", \
									"robotomy request", \
									"presidential pardon" };
	AForm			*(Intern::*createForm[ 4 ])( const std::string& ) const = { \
										&Intern::createShrubberyCreationForm, \
										&Intern::createRobotomyRequestForm, \
										&Intern::createPresidentialPardonForm, \
										&Intern::handleInvalidForm };
	
	for ( i = 0; i < 3 && formName.compare( forms[ i ] ); i++ )
		;
	return ( (this->*createForm[ i ])( parameter[ i ] ) );
}