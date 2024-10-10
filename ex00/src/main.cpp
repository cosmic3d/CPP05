/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:04:20 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 16:09:38 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Jenavarr", 150);
	Bureaucrat bureaucrat2(bureaucrat);
	std::cout << bureaucrat << std::endl;
	bureaucrat.decrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat2 << std::endl;

	return 0;
}