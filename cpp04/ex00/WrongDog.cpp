
#include "WrongDog.hpp"

WrongDog::WrongDog( void ) : WrongAnimal( "WrongDog" ) {

  std::cout << "in the middle of the street a WrongDog was just born" << std::endl;
  
}

WrongDog::WrongDog( const WrongDog & var ) : WrongAnimal( var.getType() ) {

  std::cout << "Celular division created a perfect replica of " << var.getType() << std::endl;
  
}

WrongDog::~WrongDog( void ) {
  
  std::cout << this->getType() << " was ran over a car" << std::endl;

}

std::string WrongDog::getType( void ) const {

  return this->type;
}


void  WrongDog::makeSound() const {

  std::cout << "guau guau brother" << std::endl;
}

WrongDog& WrongDog::operator = (WrongDog const &var)
{
  this->type = var.getType();
  return *this;
}