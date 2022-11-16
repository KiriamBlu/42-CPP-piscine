
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {

  std::cout << "in the middle of the street a Wrongcat was just born" << std::endl;
  
}

WrongCat::WrongCat( const WrongCat & var ) : WrongAnimal( var.getType() ) {

  std::cout << "Celular division created a perfect replica of " << var.getType() << std::endl;
  
}

WrongCat::~WrongCat( void ) {
  
  std::cout << this->getType() << " was ran over a car" << std::endl;

}

std::string WrongCat::getType( void ) const {
  return this->type;
}

void  WrongCat::makeSound() const{

  std::cout << "Miau miau mf" << std::endl;
}

WrongCat& WrongCat::operator = (WrongCat const &var)
{
  this->type = var.getType();
  return *this;
}