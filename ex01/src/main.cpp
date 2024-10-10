/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:04:20 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:04:05 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	//Tests for Form
	Form form("Form", 150, 150);
	Bureaucrat bureaucrat("Jenavarr", 150);
	std::cout << form << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;

	//Another test where the bureaucrat has a lower grade than the form so an exception is thrown
	Form form2("Form2", 140, 140);
	Bureaucrat bureaucrat2("Jenavarr", 150);
	std::cout << form2 << std::endl;
	bureaucrat2.signForm(form2);
	std::cout << form2 << std::endl;

	//Form already signed
	bureaucrat2.signForm(form);
	

	return 0;
}