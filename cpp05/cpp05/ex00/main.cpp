#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat john("John", 100);
        std::cout << john << std::endl;

        john.plusGrade();
        std::cout << john << std::endl;

        john.plusGrade();
        std::cout << john << std::endl;

        john.minusGrade();
        std::cout << john << std::endl;

        for (int i=0; i < 50; i++){john.plusGrade();};
        std::cout << john << std::endl;

        Bureaucrat mary("Mary", 0);
        std::cout << mary << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.throwException() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.throwException() << std::endl;
    }
    return 0;
}
