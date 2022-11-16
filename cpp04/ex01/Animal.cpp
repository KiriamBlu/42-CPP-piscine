
#include "Animal.hpp"

Animal::Animal( void ) : type( "AnyAnimal" ) {

  std::cout << "Animal spirit was just born. Dont assume which animal is" << std::endl;
  
}

Animal::Animal( std::string str ) : type( str ) {

  std::cout << "Animal type " << this->getType() << " was born" << std::endl;
  
}

Animal::Animal( const Animal & var ) : type( var.getType() ) {

  std::cout << "Celular split created a copy of " << var.getType() << std::endl;
  
}

Animal::~Animal( void ) {
  
  std::cout << "A hunter just killed " << this->getType() << std::endl;

}

void Animal::makeSound( void ) const {

  std::cout << "I dont think that a generic animal like me should do a sound but: PEEEEEEEELELELELELELLE =)" << std::endl;
}

std::string Animal::getType() const {

  return this->type;

}

Animal& Animal::operator = (Animal const &var){
  this->type = var.getType();
  return *this;
}
