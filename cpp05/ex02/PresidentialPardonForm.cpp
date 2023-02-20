
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ): Form("PresidentialPardon", 25, 5), _target(target) {

  return ;
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

}

std::string   PresidentialPardonForm::getTarget(void) const{
  return this->_target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &tmp) {
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

void PresidentialPardonForm::execute(Bureaucrat const &var) const{

  Form::execute(var);
  std::cout <<  var.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
