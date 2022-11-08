
#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {

  std::cout << "in the middle of the street a Dog was just born" << std::endl;
  
}

Dog::Dog( const Dog & var ) : Animal( var.get_type() ) {

  std::cout << "Celular division created a perfect replica of " << var.get_Name() << std::endl;
  
}

Dog::~Dog( void ) {
  
  std::cout << this->get_type() << " was ran over a car" << std::endl;

}

std::string Dog::get_type( void )
{
  return this->type;
}

void  Dog::makeSound() const{

  std::string << "guau guau brother" << std::endl;
}

Dog& Dog::operator = (Dog const &var)
{
  this->type = var->get_type();
  return *this;
}