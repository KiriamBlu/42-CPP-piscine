
#include "AMateria.hpp"

/*-------------------------------------<Base Materia stuff>-----------------------------------------------*/

AMateria::AMateria( void ) : _type( "DefMateria" ){

  std::cout << "DefMateria was crafted" << std::endl;
  
}

AMateria::AMateria( std::string const & type ) : _type( type ){

  std::cout << this->getType() << " was crafted"  << std::endl;
  
}

AMateria::AMateria( const AMateria & var ) : _type( var.getType() ) {

  std::cout << this->getType() << " crafting spec was copy and replicated" << std::endl;
  
}

AMateria::~AMateria( void ) {
  
  std::cout << this->getType() << " broke becouse the durability just ran out" << std::endl;

}

std::string const & AMateria::getType() const {

  return this->_type;
}

void AMateria::use(ICharacter& target) {

  std::cout << "What are you trying to use? Item " << this->getType() << " has no use" << std::endl;
}

AMateria & AMateria::operator=(const AMateria &tmp) {

  this->_type = tmp->getType();
  std::cout << "One base block was adjusted to replicate " << tmp->getType() <<  std::endl;
  return *this;
}


/*-------------------------------------------<ICY Stuff>--------------------------------------------------*/

Ice::Ice( void ) {

  this->_type = "ice";
  std::cout << "A block of ice fell of a iceberg" << std::endl;
  
}

Ice::Ice( std::string const & type ) {

  this->_type = type
  std::cout << "A icy pice of " << this->getType() << " was crafted"  << std::endl;
  
}

Ice::Ice( const Ice & var ) {

  this->_type = var.getType();
  std::cout << this->getType() << " crafting spec was copy and replicated" << std::endl;
  
}

Ice::~Ice( void ) {
  
  std::cout << this->getType() << " broke becouse it was a hot day and melted down" << std::endl;

}

AMateria* Ice::clone() const {
  
  return new Ice;  
}

std::string const & Ice::getType() const {

  return this->_type;
}

void Ice::use(ICharacter& target) {

  std::cout << "You smash the ice crystal and obtained frost powers. You cast a ice ray to attack " << target->getType() << std::endl;
}

Ice & Ice::operator=(const Ice &tmp) {

  this->_type = tmp->getType();
  std::cout << "An icy shard was transformed into " << tmp->getType() <<  std::endl;
  return *this;
}

/*-------------------------------------------<CURE Stuff>------------------------------------------------*/

Cure::Cure( void ) {

  this->_type = "Cure";
  std::cout << "You find a healing potion" << std::endl;
  
}

Cure::Cure( std::string const & type ) {

  this->_type = type
  std::cout << "Joining different materials that you have arround you craft a new " << type << std::endl;
  
}

Cure::Cure( const Cure & var ) {

  this->_type = var.getType();
  std::cout << this->getType() << " crafting spec was copy and replicated" << std::endl;
  
}

Cure::~Cure( void ) {
  
  std::cout << this->getType() << " sliped out of your hands and dropped to the floor and broke" << std::endl;

}

AMateria* Cure::clone() const {
  
  return new Cure;  
}

std::string const & Cure::getType() const {

  return this->_type;
}

void Cure::use(ICharacter& target) {

  std::cout << "You used your " << target->getType() << " to heal " << target.getType() << std::endl;
}

Cure & Cure::operator=(const Cure &tmp) {

  this->_type = tmp->getType();
  std::cout << "One base block was adjusted to replicate a " << tmp->getType() <<  std::endl;
  return *this;
}
