#include "ScavTrap.hpp"

/*--------------Constructos and destructors-------------*/

ScavTrap::ScavTrap( void )  : ClapTrap( "DefScavTrap" ){
  this->set_Hp(100);
  this->set_Stamina(50);
  this->set_Dmg(20);
  std::cout << "Default ScavTrap was awaken" << std::endl;
  
}

ScavTrap::ScavTrap( std::string str ) : ClapTrap( str ){

  this->set_Hp(100);
  this->set_Stamina(50);
  this->set_Dmg(20);
  std::cout << "ScavTrap: " << str << " built" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & var ) : ClapTrap( var.get_Name() ){
  this->set_Hp(var.get_Hp());
  this->set_Stamina(var.get_Stamina());
  this->set_Dmg(var.get_Dmg());
  std::cout << "A perfect replica of original ScavTrap " <<  var.get_Name() << " was born" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
  
  std::cout << "ScavTrap tryed to run through a wall" << std::endl;

}

/*----------------------Funtions----------------------*/

void ScavTrap::attack( std::string const name ){

  std::cout << "ScavTrap " << this->get_Name() << " has attacked " << name << " dealing " << this->get_Dmg() << " points of damage" << std::endl;
}

void ScavTrap::guardGate( void ){

  std::cout << "ScavTrap has entered Gate keeper mode" << std::endl;
}

/*----------------------Operators----------------------*/

ScavTrap& ScavTrap::operator = (ScavTrap const &var){
  this->set_Name(var.get_Name());
  this->set_Hp(var.get_Hp());
  this->set_Stamina(var.get_Stamina());
  this->set_Dmg(var.get_Dmg());
  return *this;
}