/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:24:52 by jenavarr          #+#    #+#             */
/*   Updated: 2024/10/10 17:04:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
	private:
		std::string const name;
		bool signedForm;
		int const gradeToSign;
		int const gradeToExecute;
	public:
		Form();
		Form(const Form& form);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();

		// Copy assignment operator
		Form& operator=(const Form& form);

		// Getters
		std::string getName() const;
		bool getSignedForm() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Sign form
		void beSigned(Bureaucrat& bureaucrat);

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
		//FormAlreadySignedException
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "Form is already signed";
				}
		};

};
//Override << operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif