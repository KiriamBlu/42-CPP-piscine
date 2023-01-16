
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {

  std::cout << "Default constructor called" << std::endl;
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string str ) {

  (void) str;
  std::cout << "Parameter constructor called" << std::endl;
  return ;
  
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & var ) {
  
  std::cout << "Copy constructor called" << std::endl;
  *this = var;
  return ;
  
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
  
  std::cout << "Destructor called" << std::endl;
  return ;

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &tmp) {

  (void) tmp;
  std::cout << "Operator equalizer called" << std::endl;
  return (*this);
  
}

std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp) {

  (void) tmp;
	os << std::endl << "Operator output called" << std::endl;
	return (os);
  
}
