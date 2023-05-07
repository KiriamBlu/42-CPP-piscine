#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat Josemaria("Josemaria", 150);

        Form basicForm("Bform", 100, 1);
        Form midForm("Mform", 50, 50);
        Form highForm("Hform", 1, 50);

        std::cout << "----- Inicio de simulación -----" << std::endl;
        std::cout << basicForm << std::endl;
        std::cout << midForm << std::endl;
        std::cout << highForm << std::endl;
        std::cout << Josemaria << std::endl;

        Josemaria.signForm(basicForm);
        std::cout << "Formulario básico firmado por " << Josemaria.getName() << std::endl;
        std::cout << basicForm << std::endl;

        Josemaria.signForm(midForm);
        std::cout << "Formulario medio intentado firmar por " << Josemaria.getName() << std::endl;
        std::cout << midForm << std::endl;

       for (int i=0; i < 50; i++){Josemaria.plusGrade();};
        std::cout << "Burócrata " << Josemaria.getName() << " ascendido a grado " << Josemaria.getGrade() << std::endl;
        std::cout << Josemaria << std::endl;

        Josemaria.signForm(midForm);
        std::cout << "Formulario medio firmado por " << Josemaria.getName() << std::endl;
        std::cout << midForm << std::endl;

        Josemaria.signForm(highForm);
        std::cout << "Formulario de grado alto intentado firmar por " << Josemaria.getName() << std::endl;
        std::cout << highForm << std::endl;

        for (int i=0; i < 50; i++){Josemaria.plusGrade();};
        std::cout << "Burócrata " << Josemaria.getName() << " ascendido a grado " << Josemaria.getGrade() << std::endl;
        std::cout << Josemaria << std::endl;

        Josemaria.signForm(highForm);
        std::cout << "Formulario de grado alto firmado por " << Josemaria.getName() << std::endl;
        std::cout << highForm << std::endl;

        std::cout << "----- Fin de simulación -----" << std::endl;
        Form impossibleForm("Impossible", 200, -1);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.throwException() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.throwException() << std::endl;
    }
    catch (const Form::GradeTooHighException& e) {
        std::cout << e.throwException() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << e.throwException() << std::endl;
    }

    system("leaks Bureaucrat");
    return 0;
}
