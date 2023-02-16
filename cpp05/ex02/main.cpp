#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try{
		Bureaucrat Josemaria("Josemaria", 150);
		Bureaucrat Paco("Paco", 150);
		Bureaucrat Joseluis("Joseluis", 150);

		ShrubberyCreationForm arbol("Josemaria");
		PresidentialPardonForm contrato("Paco")
		RobotomyRequestForm lavado("Joseluis"):


		std::cout << arbol << std::endl;
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(arbol);
		std::cout << Joseluis << std::endl;
		Joseluis.signForm(arbol);
		Joseluis.plusGrade(50)
		std::cout << Joseluis << std::endl;
		Joseluis.signForm(arbol);
		std::cout << Josemaria << std::endl;
		Josemaria.plusGrade(50);
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(midForm);
		std::cout << midForm << std::endl;
		Josemaria.plusGrade(50);
		std::cout << Josemaria  << std::endl;
		std::cout << highForm <<   std::endl;
		Josemaria.signForm(midForm);
		Josemaria.signForm(highForm);
		Josemaria.plusGrade(50); //CAMBIAR
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(highForm);
		std::cout << highForm <<   std::endl;
		Josemaria.minusGrade(150); //CAMBIAR
		std::cout << Josemaria << std::endl;		
	}
	catch( Bureaucrat::GradeTooHighException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( Bureaucrat::GradeTooLowException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( Form::GradeTooHighException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( Form::GradeTooLowException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
}