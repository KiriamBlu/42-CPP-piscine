

// TO DO COPY CONSTRUCTOR DOG AND CAT COPY BRAIN IDEAS.

#include "Brain.hpp"

Brain::Brain( void ) {

  std::cout << "Default constructor called" << std::endl;
  
}

Brain::Brain( const Brain & var ) {

  for ( int x = 0; x < 100,x++)
    this->set_idea(x , var->get_idea(x));
  std::cout << "Copy constructor called" << std::endl;
}

Brain::~Brain( void ) {
  
  std::cout << "Destructor called" << std::endl;

}

Brain & Brain::operator=(const Brain &tmp) {
  if (this != &tmp)
    for ( int x = 0; x < 100,x++)
      this->set_idea(x , var->get_idea(x));
  std::cout << "Operator equalizer called" << std::endl;

}

std::string Brain::get_idea( unsigned int number ){
  if ( number <= 100 )
    return this->_idea[number];
  std::cout << "This idea that you are searching is higher than the maximun number that a animal can learn" << std::endl;
  return NULL;
}

void Brain::set_idea( unsigned int number, std::string new_idea ){
  if ( number >= 100 )
  {
    std::cout << "You cant make an animal learn this, is too much" << std::endl;
    return ;
  } 
  this->_idea[number] = new_idea;
}