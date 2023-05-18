#include "Intern.hpp"

Intern::Intern() {
	Intern::makers[0] = &Intern::make1;
	Intern::makers[1] = &Intern::make2;
	Intern::makers[2] = &Intern::make3;
	this->dict[0] = "ShrubberyCreation";
	this->dict[1] = "RobotomyRequest";
	this->dict[2] = "PresidentialPardon";
}

Intern::Intern( Intern const &other ) {
	(void) other;
}

Intern::~Intern() {}

AForm*	Intern::make1( std::string target )  {
	std::cout << "Intern creates ShrubberyCreation " << target << std::endl;
	return new ShrubberyCreationForm( target ); 
}

AForm*	Intern::make2( std::string target )  {
	std::cout << "Intern creates RobotomyRequest for " << target << std::endl;
	return new RobotomyRequestForm( target );
}

AForm*	Intern::make3( std::string target )  {
	std::cout << "Intern creates PresidentialPardon for " << target << std::endl;
	return new PresidentialPardonForm( target );
}

AForm *Intern::makeForm(const std::string& formName, const std::string& target) {

		for (int x = 0; x < 3; x++)
			if (this->dict[x].compare(formName) == 0)
				return (this->*makers[x])(target);

		
		throw Intern::FormNotFoundException();

		return NULL;
}
