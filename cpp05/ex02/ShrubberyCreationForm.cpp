
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string new_target ): Form("RobotomyRequest", 25, 5), _target(new_target) {

  return ;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

std::string   ShrubberyCreationForm::getTarget(void){
  return this->_target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp) {

  (void) tmp;
  os << std::endl << static_cast<Form>(tmp) << "Signned: " << tmp->getSigned()  << std::endl;
  return (os);
  
}


void ShrubberyCreationForm::execute(Bureaucrat &tmp){

  Form::execute(tmp)
  std::cout << "Tells us" << tmp.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl
}

