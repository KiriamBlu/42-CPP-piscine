
#include "ICharacter.hpp"
#include "AMateria.hpp"


/*---------------------------<Character stuff>-----------------------------*/

//PRIVATE

void Character::init_inventory( void ) {
  
  for (int x = 0; x < 4; x++)
    this->_inventory[x] = NULL;
}

void Character::copy_inventory( const Character & var ) {

  for ( int x = 0; x < 4; x++ )
    if ( var._inventory[x] != NULL )
      this->_inventory[x] = var._inventory[x]->clone();
}

void Character::free_inventory( void ) {

  for ( int x = 0; x < 4; x++ )
    if ( this->_inventory[x] != NULL )
      delete this->_inventory[x];
}

//PUBLIC

Character::Character( void ) : _identity( "Link" ){

  this->init_inventory();
  std::cout << "A new hero awakens from the shadows" << std::endl;
  
}

Character::Character( std::string str ) : _identity( str ){

  this->init_inventory();
  std::cout << "Parameter constructor called" << std::endl;
  
}

Character::Character( const Character & var ) : _identity( var.getName() ) {

  this->init_inventory();
  this->copy_inventory( var );
  std::cout << "Copy constructor called" << std::endl;
  
}

Character::~Character( void ) {
  
  this->free_inventory();
  std::cout << "After a long journey," << this->getName() << " finally rests" << std::endl;

}

Character & Character::operator=(const Character &tmp) {

  if ( this != &tmp )
  {
    this->free_inventory();
    this->init_inventory();
    this->copy_inventory( tmp );
    std::cout << "From " << this->getName() << "'s shadow, a replica of himself materialized" << std::endl;
  }
  return *this;
}

std::string const & Character::getName( void ) const {
  return this->_identity;
}

void Character::equip( AMateria* m ) {

  for (int x = 0 ; x < 4; x++)
  {
    if (this->_inventory[x] == NULL)
    {
      this->_inventory[x] = m;
      return ;
    }
  }
}

void Character::unequip( int idx ) {

  if (idx < 0 && idx > 3)
  {
    if (this->_inventory[idx] != NULL)
      this->_inventory[idx] = NULL;
  }
  else
    std::cout << "The slot is already in use or not accesible" << std::endl;
}
    
void Character::use( int idx, ICharacter& target ) {
  if (idx < 0 && idx > 3)
  {
    if (this->_inventory[idx] != NULL)
      this->_inventory[idx]->use(target);
  }
  else
    std::cout << "The inventory slot selected cant be used" << std::endl;
}

