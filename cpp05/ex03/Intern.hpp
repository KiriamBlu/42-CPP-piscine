#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"
#include <exception>

class AForm;

class	Intern {

	private:
		AForm*	(*makers[3])(std::string);
		AForm*	make1(std::string);
		AForm*	make2(std::string);
		AForm*	make3(std::string);
		const std::string dict[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};

	public:

		Intern();
		Intern(Intern const &other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw(){
					return "Form not found.";
				}
		};

};

#endif
