
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string new_target ): Form("RobotomyRequest", 25, 5), _target(new_target) {

  return ;
}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

std::string   RobotomyRequestForm::getTarget(void){
  return this->_target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm &tmp) {

  (void) tmp;
  os << std::endl << static_cast<Form>(tmp) << "Signned: " << tmp->getSigned()  << std::endl;
  return (os);
  
}


void RobotomyRequestForm::execute(Bureaucrat &tmp){

  Form::execute(tmp)
  std::cout << "Tells us" << tmp.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl
}
