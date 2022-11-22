
#include "ICharacter.hpp"

ICharacter::ICharacter( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

ICharacter::ICharacter( std::string str ) {

  std::cout << "Parameter constructor called" << std::endl;
  
}

ICharacter::ICharacter( const ICharacter & var ) {

  std::cout << "Copy constructor called" << std::endl;
  
}

ICharacter::~ICharacter( void ) {
  
  std::cout << "Destructor called" << std::endl;

}

ICharacter & ICharacter::operator=(const ICharacter &tmp) {

  std::cout << "Operator equalizer called" << std::endl;

}

std::ostream &operator<<(std::ostream& os, const ICharacter &tmp) {

	os << std::endl << "Operator output called" << std::endl;
	return (os);
  
}
