/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:04:20 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/11 16:36:38 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat john("John", 1);

	AForm *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		john.signAForm(*rrf);
		john.executeForm(*rrf);
	}

	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (rrf)
	{
		john.signAForm(*rrf);
		john.executeForm(*rrf);
	}
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("presidential pardon", "home");
	if (rrf)
	{
		john.signAForm(*rrf);
		john.executeForm(*rrf);
	}
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("cualquier mierda", "home");
	if (rrf)
	{
		john.signAForm(*rrf);
		john.executeForm(*rrf);
	}
	std::cout << std::endl;
	return 0;
}