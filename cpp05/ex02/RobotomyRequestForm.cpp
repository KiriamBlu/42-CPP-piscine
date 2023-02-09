
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) {

  std::cout << "Default constructor called" << std::endl;
  return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string str ) {

  (void) str;
  std::cout << "Parameter constructor called" << std::endl;
  return ;
  
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & var ) {
  
  std::cout << "Copy constructor called" << std::endl;
  *this = var;
  return ;
  
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
  
  std::cout << "Destructor called" << std::endl;
  return ;

}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &tmp) {

  (void) tmp;
  std::cout << "Operator equalizer called" << std::endl;
  return (*this);
  
}

std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm &tmp) {

  (void) tmp;
	os << std::endl << "Operator output called" << std::endl;
	return (os);
  
}
