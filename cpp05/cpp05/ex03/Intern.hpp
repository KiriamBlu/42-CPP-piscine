#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class	Intern {

	private:
		AForm*	(Intern::*makers[3])(std::string);
		AForm*	make1(std::string);
		AForm*	make2(std::string);
		AForm*	make3(std::string);
		std::string dict[3];

	public:

		Intern();
		Intern(Intern const &other);
		~Intern();

		AForm *makeForm(const std::string& formName, const std::string& target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *throwException() const throw(){
					return "Form type not found.";
				}
		};

};

#endif
