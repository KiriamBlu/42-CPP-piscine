#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try{
		Bureaucrat Josemaria("Josemaria", 150);
		Form basicForm("Bform",100, 1);
		Form midForm("Mform", 50, 50);
		Form highForm("Hform", 1, 50);

		std::cout << basicForm << std::endl;
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(basicForm);
		Josemaria.plusGrade(50);
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(basicForm);
		std::cout << midForm << std::endl;
		Josemaria.signForm(midForm);
		std::cout << Josemaria << std::endl;
		Josemaria.plusGrade(50);
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(midForm);
		Josemaria.plusGrade(50);
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(midForm);
		std::cout << highForm << std::endl;
		Josemaria.signForm(highForm);
		Josemaria.plusGrade(50); //CAMBIAR
		std::cout << Josemaria << std::endl;
		Josemaria.signForm(highForm);
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