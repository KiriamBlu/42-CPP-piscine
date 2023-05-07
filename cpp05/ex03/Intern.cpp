#include "Intern.hpp"

Intern::Intern() {
	Intern::makers[0] = &Intern::make1;
	Intern::makers[1] = &Intern::make2;
	Intern::makers[2] = &Intern::make3;
	this.dict[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
}

Intern::Intern( Intern const &other ) {
	(void) other;
}

Intern::~Intern() {}

Form*	Intern::make1( std::string target )  {
	std::cout << "Intern creates ShrubberyCreation" << std::endl;
	return new ShrubberyCreationForm( target ); 
}

Form*	Intern::make2( std::string target )  {
	std::cout << "Intern creates RobotomyRequest" << std::endl;
	return new RobotomyRequestForm( target );
}

Form*	Intern::make3( std::string target )  {
	std::cout << "Intern creates PresidentialPardon" << std::endl;
	return new PresidentialForm( target );
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
		AForm* form = nullptr;


		switch (formName) {
				case "ShrubberyCreation":
						form = new ShrubberyCreationForm(target);
						break;
				case "RobotomyRequest":
						form = new RobotomyRequestForm(target);
						break;
				case "PresidentialPardon":
						form = new PresidentialPardonForm(target);
						break;
				default:
						throw Intern::FormNotFoundException();
						break;
		}

		if (form) {
				std::cout << "Intern creates " << formName << std::endl;
		}

		return form;
}
