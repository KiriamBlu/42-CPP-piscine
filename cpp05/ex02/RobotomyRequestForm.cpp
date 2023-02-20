
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ): Form("RobotomyRequest", 72, 45), _target(target) {

  return ;
}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

std::string   RobotomyRequestForm::getTarget(void) const{
  return this->_target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form Name: " << form.getName() << ", Sign Grade: " << form.getSigGrade() << ", Execute Grade: " << form.getExeGrade() << ", Signed: " << form.getSigned();
    return os;
}

void RobotomyRequestForm::execute(Bureaucrat const &var) const{
  Form::execute(var);
  std::cout << "*-DRILLING-NOISES-*" << std::endl;
  if (rand() == 1)
    std::cout << var.getName() << " has been sucessfully robotomized" << std::endl;
  else
    std::cout << "Process of robotomization in subject "  << var.getName() << " has failed! please exit the building calmly" << std::endl << "*-The-screams-echoes-in-the-building-*" << std::endl;
}
