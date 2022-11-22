
#include "Dog.hpp"

Dog::Dog( void ) : DogBrain( new Brain ) {

  this->set_type("Dog");
  std::cout << "In the middle of the street a Dog was just born" << std::endl;
  
}

Dog::Dog( const Dog & var ) {

  if (this != &var)
  { 
    this->set_type("Dog");
    delete this->DogBrain;
    Brain* auxBrain = new Brain;
    for ( int x = 0; x < 100; x++)
      auxBrain->set_idea(x , var.DogBrain->get_idea(x));
    this->DogBrain = auxBrain;
    this->type = var.getType();
  }
  std::cout << "Celular division created a perfect replica of " << var.getType() << std::endl;
  
}

Dog::~Dog( void ) {
  
  delete this->DogBrain;
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
  if (this != &var)
  { 
    delete this->DogBrain;
    Brain* auxBrain = new Brain;
    for ( int x = 0; x < 100; x++)
      auxBrain->set_idea(x , var.DogBrain->get_idea(x));
    this->DogBrain = auxBrain;
    this->type = var.getType();
  }
  return *this;
}