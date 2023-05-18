#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try{
		Intern intern;
		Bureaucrat Josemaria("Josemaria", 150);

		AForm* form1 = intern.makeForm("ShrubberyCreation", "garden");
    	AForm* form2 = intern.makeForm("RobotomyRequest", "robot");
    	AForm* form3 = intern.makeForm("PresidentialPardon", "president");

		for (int i=0; i< 149; i++){Josemaria.plusGrade();};

		std::cout << Josemaria << std::endl;


		form1->beSigned(Josemaria);
		form2->beSigned(Josemaria);
		form3->beSigned(Josemaria);

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		if (form1 != nullptr) {
	        form1->execute(Josemaria);
	        delete form1;
    	}
    	if (form2 != nullptr) {
        	form2->execute(Josemaria);
        	delete form2;
    	}
	    if (form3 != nullptr) {
	        form3->execute(Josemaria);
	        delete form3;
	    }
	    try {
        	AForm* form4 = intern.makeForm("UnknownForm", "target");
        	std::cout << form4 << std::endl;
	    }
	    catch (const Intern::FormNotFoundException& e) {
        	std::cerr << "Error: " << e.throwException() << std::endl;
    	}
		
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


