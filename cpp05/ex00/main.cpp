#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Josemaria("Josemaria", 18333);
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.throwException() << std::endl;
	}
	catch(Bureaucrat::GradeTooLow & e)
	{
		std::cout << e.throwException() << std::endl;
	}
}