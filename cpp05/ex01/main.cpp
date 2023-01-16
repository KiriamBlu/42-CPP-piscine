#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat Josemaria("Josemaria", 100);

		std::cout << "Josemaria " << Josemaria.getGrade() << std::endl;
		Josemaria.plusGrade( 99 );
		std::cout << Josemaria.getGrade() << std::endl;
		Josemaria.plusGrade( 1 );
		std::cout << Josemaria.getGrade() << std::endl;
		Josemaria.plusGrade( 150 );
	}
	catch( Bureaucrat::GradeTooHighException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
	catch( Bureaucrat::GradeTooLowException & e )
	{
		std::cout << e.throwException() << std::endl;
	}
}