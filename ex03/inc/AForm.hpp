#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
private:
		std::string const name;
		bool signedAForm;
		int const gradeToSign;
		int const gradeToExecute;

public:
		// Constructor y destructor
		AForm();
		AForm(const AForm& form);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();  // Destructor virtual para polimorfismo

		// Operador de asignación
		AForm& operator=(const AForm& form);

		// Getters
		std::string getName() const;
		bool getSignedAForm() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Función para firmar el formulario
		void beSigned(Bureaucrat& bureaucrat);

		// Excepciones personalizadas
		class GradeTooHighException : public std::exception {
		public:
				virtual const char* what() const throw() {
						return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
		public:
				virtual const char* what() const throw() {
						return "Grade is too low";
				}
		};

		class AFormAlreadySignedException : public std::exception {
		public:
				virtual const char* what() const throw() {
						return "Form is already signed";
				}
		};

		class AFormNotSignedException : public std::exception {
		public:
				virtual const char* what() const throw() {
						return "Form is not signed";
				}
		};

		// Método abstracto puro (hace que AForm sea abstracta)
		virtual void execute(Bureaucrat const & executor) const = 0;
};

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
