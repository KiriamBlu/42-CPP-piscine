
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

Bureaucrat::Bureaucrat( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

Bureaucrat::Bureaucrat( const Bureaucrat & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

Bureaucrat::~Bureaucrat( void ) {
  
  std::cout << "Destructor called" << std::endl;

}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &tmp) {

  std::cout << "Operator equalizer called" << std::endl;

}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &tmp) {

	os << std::endl << "Bureaucrat: " << tmp.getName() << std::endl;
	return (os);
  
}
