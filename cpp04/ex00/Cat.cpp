
#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {

  std::cout << "in the middle of the street a cat was just born" << std::endl;
  
}

Cat::Cat( const Cat & var ) : Animal( var.get_type() ) {

  std::cout << "Celular division created a perfect replica of " << var.get_Name() << std::endl;
  
}

Cat::~Cat( void ) {
  
  std::cout << this->get_type() << " was ran over a car" << std::endl;

}

std::string Cat::get_type( void )
{
  return this->type;
}

void  Cat::makeSound() const{

  std::string << "Miau miau mf" << std::endl;
}

Cat& Cat::operator = (Cat const &var)
{
  this->type = var->get_type();
  return *this;
}