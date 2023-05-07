#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try{
		Bureaucrat Josemaria("Josemaria", 150);

		ShrubberyCreationForm shrubberyForm("garden");
		RobotomyRequestForm robotomyForm("John Doe");
		PresidentialPardonForm pardonForm("Jane Doe");

		for (int i=0; i< 140; i++){Josemaria.plusGrade();};

		std::cout << Josemaria << std::endl;

		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		shrubberyForm.beSigned(Josemaria);
		robotomyForm.beSigned(Josemaria);
		pardonForm.beSigned(Josemaria);

		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		shrubberyForm.execute(Josemaria);
		robotomyForm.execute(Josemaria);
		pardonForm.execute(Josemaria);

	
		for (int i=0; i< 150; i++){Josemaria.minusGrade();};
		pardonForm.beSigned(Josemaria); // Should throw Form::GradeTooLowException
		shrubberyForm.execute(Josemaria); // Should throw Form::FormNotSignedException
		robotomyForm.execute(Josemaria); // Should throw Form::GradeTooLowException

	}
	catch( Bureaucrat::GradeTooHighException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( Bureaucrat::GradeTooLowException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( AForm::GradeTooHighException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( AForm::GradeTooLowException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( AForm::AFormNotSigned & e )
	{
		std::cout << e.throwException() << std::endl;
	}
}
