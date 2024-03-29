
#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {

  std::cout << "in the middle of the street a Dog was just born" << std::endl;
  
}

Dog::Dog( const Dog & var ) : Animal( var.getType() ) {

  std::cout << "Celular division created a perfect replica of " << var.getType() << std::endl;
  
}

Dog::~Dog( void ) {
  
  std::cout << this->getType() << " was ran over a car" << std::endl;

}

std::string Dog::getType( void ) const {

  return this->type;
}


void  Dog::makeSound() const {

  std::cout << "guau guau brother" << std::endl;
}

Dog& Dog::operator = (Dog const &var)
{
  this->type = var.getType();
  return *this;
}