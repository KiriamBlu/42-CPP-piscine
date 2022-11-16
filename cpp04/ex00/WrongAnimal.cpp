
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type( "AnyWrongAnimal" ) {

  std::cout << "WrongAnimal spirit was just born. Dont assume which Wronganimal is" << std::endl;
  
}

WrongAnimal::WrongAnimal( std::string str ) : type( str ) {

  std::cout << "WrongAnimal type " << this->getType() << " was born" << std::endl;
  
}

WrongAnimal::WrongAnimal( const WrongAnimal & var ) : type( var.getType() ) {

  std::cout << "Celular split created a copy of " << var.getType() << std::endl;
  
}

WrongAnimal::~WrongAnimal( void ) {
  
  std::cout << "A hunter just killed " << this->getType() << std::endl;

}

void WrongAnimal::makeSound( void ) const {

  std::cout << "I dont think that a generic Wronganimal like me should do a sound but: PEEEEEEEELELELELELELLE =)" << std::endl;
}

std::string WrongAnimal::getType() const {

  return this->type;

}

WrongAnimal& WrongAnimal::operator = (WrongAnimal const &var){
  this->type = var.getType();
  return *this;
}
