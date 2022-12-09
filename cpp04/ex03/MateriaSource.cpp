
#include "MateriaSource.hpp"

//PRIVATE

void MateriaSource::init_inventory( void ) {
  
  for (int x = 0; x < 4; x++)
    this->_inventory[x] = NULL;
}

void MateriaSource::copy_inventory( const MateriaSource & var ) {

  for ( int x = 0; x < 4; x++ )
    if ( var._inventory[x] != NULL )
      this->_inventory[x] = var._inventory[x]->clone();
}

void MateriaSource::free_inventory( void ) {

  for ( int x = 0; x < 4; x++ )
    if ( this->_inventory[x] != NULL )
      delete this->_inventory[x];
}

//PUBLIC

MateriaSource::MateriaSource( void ) {

  this->init_inventory();  
}

MateriaSource::MateriaSource( const MateriaSource & var ) {

  this->init_inventory();
  this->copy_inventory( var );
  
}

MateriaSource::~MateriaSource( void ) {
  
  this->free_inventory();

}

void MateriaSource::learnMateria(AMateria* aux)
{
  if ( aux != NULL )
  {
    for ( int x = 0; x < 4; x++ )
    {
      if ( this->_inventory[x] == aux)
      {
        std::cout << "This materia is already learnt" << std::endl;
        return;
      }
    }
    for ( int i = 0; i < 4; i++ )
    {
      if ( this->_inventory[i] == NULL)
      {
        this->_inventory[i] = aux;
        return;
      }
    }
    std::cout << "No space left in inventory" << std::endl;
  }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for (int x = 0; x < 4; x++)
  {
    if (this->_inventory[x]->getType().length() != 0 && this->_inventory[x]->getType().compare(type) == 0)
    {
      AMateria* ret = this->_inventory[x]->clone();
      return ret;
    }  
  }
  std::cout << "Materia not found" << std::endl;
  return NULL;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &tmp) {

  if ( this != &tmp )
  {
    this->free_inventory();
    this->init_inventory();
    this->copy_inventory( tmp );
  }
  return *this;
}
