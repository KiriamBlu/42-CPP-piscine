
#include "FragTrap.hpp"

/*--------------Constructos and destructors-------------*/

FragTrap::FragTrap( void )  : ClapTrap( "DefFragTrap" ){
  this->set_Hp(100);
  this->set_Stamina(50);
  this->set_Dmg(20);
  std::cout << "Default FragTrap was awaken" << std::endl;
  
}

FragTrap::FragTrap( std::string str ) : ClapTrap( str ){

  this->set_Hp(100);
  this->set_Stamina(50);
  this->set_Dmg(20);
  std::cout << "FragTrap: " << str << " built" << std::endl;
}

FragTrap::FragTrap( const FragTrap & var ) : ClapTrap( var.get_Name() ){
  this->set_Hp(var.get_Hp());
  this->set_Stamina(var.get_Stamina());
  this->set_Dmg(var.get_Dmg());
  std::cout << "A perfect replica of original FragTrap " <<  var.get_Name() << " was born" << std::endl;
}

FragTrap::~FragTrap( void ) {
  
  std::cout << "FragTrap tryed to run through a wall" << std::endl;

}

void FragTrap::attack(std::string const & target){
 
  std::cout << "FragTrap " << this->get_Name() << " attack " << target << ", causing " << this->get_Dmg() << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys( void ){

  std::cout << "FragTrap " << this->get_Name() << " raises its hand and shouts: !High Five¡" << std::endl;
}

FragTrap& FragTrap::operator = (FragTrap const &var){
  this->set_Name(var.get_Name());
  this->set_Hp(var.get_Hp());
  this->set_Stamina(var.get_Stamina());
  this->set_Dmg(var.get_Dmg());
  return *this;
}