
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) {

  std::cout << "Default constructor called" << std::endl;
  return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string str ) {

  (void) str;
  std::cout << "Parameter constructor called" << std::endl;
  return ;
  
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & var ) {
  
  std::cout << "Copy constructor called" << std::endl;
  *this = var;
  return ;
  
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
  
  std::cout << "Destructor called" << std::endl;
  return ;

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &tmp) {

  (void) tmp;
  std::cout << "Operator equalizer called" << std::endl;
  return (*this);
  
}

std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm &tmp) {

  (void) tmp;
	os << std::endl << "Operator output called" << std::endl;
	return (os);
  
}
