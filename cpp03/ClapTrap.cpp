#include "ClapTrap.hpp"

/*--------------Constructos and destructors-------------*/

ClapTrap::ClapTrap( void ) : _name("Default"){

  std::cout << "Default ClapTrap awoke" << std::endl;
  
}

ClapTrap::ClapTrap( std::string str ) : _name(str) {

  std::cout << "ClapTrap: " << str << "just became alive" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & var ) {
  std::cout << "A perfect replica of original ClapTrap has been created" << std::endl;
  this = var;
}

ClapTrap::ClapTrap~( void ) {
  
  std::cout << "ClapTrap imploded" << std::endl;

}

/*----------------------Mandatory----------------------*/

void ClapTrap::attack(std::string const & target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}

/*-----------------Getters and setters-----------------*/


int ClapTrap::get_Name( void )
{
  return(this->_name);
}

int ClapTrap::get_Hp( void )
{
  return(this->_healthpoints);
}

int ClapTrap::get_Stamina( void )
{
  return(this->_energypoints);
}

int ClapTrap::get_Dmg( void )
{
  return(this->_damage);
}

void ClapTrap::set_Name( std::string new_name )
{
  this->_name = new_name;
}

void ClapTrap::set_Hp( int new_hp )
{
  this->_healthpoints = new_hp;
}

void ClapTrap::set_Stamina( int new_stamina )
{
  this->_energypoints =  new_stamina;
}

void ClapTrap::set_Dmg( int new_Dmg )
{
  this->_damage = new_Dmg;
}
