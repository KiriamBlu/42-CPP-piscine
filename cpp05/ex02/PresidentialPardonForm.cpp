
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string new_target ): Form("PresidentialPardon", 25, 5), _target(new_target) {

  return ;
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

}

std::string   PresidentialPardonForm::getTarget(void){
  return this->_target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm &tmp) {

  (void) tmp;
	os << std::endl << static_cast<Form>(tmp) << "Signned: " << tmp->getSigned()  << std::endl;
	return (os);
  
}


void PresidentialPardonForm::execute(Bureaucrat &tmp){

  Form::execute(tmp)
  std::cout <<  tmp.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl
}
