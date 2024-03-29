
#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {

  std::cout << "in the middle of the street a cat was just born" << std::endl;
  
}

Cat::Cat( const Cat & var ) : Animal( var.getType() ) {

  std::cout << "Celular division created a perfect replica of " << var.getType() << std::endl;
  
}

Cat::~Cat( void ) {
  
  std::cout << this->getType() << " was ran over a car" << std::endl;

}

std::string Cat::getType( void ) const {
  return this->type;
}

void  Cat::makeSound() const{

  std::cout << "Miau miau mf" << std::endl;
}

Cat& Cat::operator = (Cat const &var)
{
  this->type = var.getType();
  return *this;
}