/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:04:20 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:17:56 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

int main()
{
	//Tests for AForm
	AForm form("AForm", 150, 150);
	Bureaucrat bureaucrat("Jenavarr", 150);
	std::cout << form << std::endl;
	bureaucrat.signAForm(form);
	std::cout << form << std::endl;

	//Another test where the bureaucrat has a lower grade than the form so an exception is thrown
	AForm form2("AForm2", 140, 140);
	Bureaucrat bureaucrat2("Jenavarr", 150);
	std::cout << form2 << std::endl;
	bureaucrat2.signAForm(form2);
	std::cout << form2 << std::endl;

	//AForm already signed
	bureaucrat2.signAForm(form);
	

	return 0;
}