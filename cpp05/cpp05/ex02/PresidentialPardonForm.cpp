
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ): AForm("PresidentialPardon", 25, 5), _target(target) {

  return ;
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & var ): AForm(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
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
  AForm::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
    os << "Form Name: " << form.getName() << ", Sign Grade: " << form.getSigGrade() << ", Execute Grade: " << form.getExeGrade() << ", Signed: " << form.getSigned();
    return os;
}

void PresidentialPardonForm::execute(Bureaucrat const &var) const{

  AForm::execute(var);
  std::cout <<  var.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
