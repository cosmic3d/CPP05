/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:33:31 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:17:56 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class Bureaucrat{
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		// Copy assignment operator
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);

		// Getters
		std::string getName() const;
		int getGrade() const;

		// Increment or decrement grade
		void incrementGrade();
		void decrementGrade();

		//Sign form print
		void signAForm(AForm &form);


		//GradeTooHighException
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Grade is too high";
				}
		};
		//GradeTooLowException
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Grade is too low";
				}
		};
};
	//Override << operator
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif