#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :  ScavTrap(), FragTrap() {

  this->set_Name( "DefDiamond" );
  this->set_Hp(this->FragTrap::get_Hp());
  this->set_Dmg(this->ScavTrap::get_Dmg());
  this->set_Stamina(this->FragTrap::get_Stamina());

  std::cout << "Default DiamondTrap awoke" << std::endl;
}

DiamondTrap::DiamondTrap( std::string str ) :  ScavTrap( str ), FragTrap( str ) {
  this->set_Name( str );
  this->set_Hp(this->FragTrap::get_Hp());
  this->set_Dmg(this->ScavTrap::get_Dmg());
  this->set_Stamina(this->FragTrap::get_Stamina());
  std::cout << "DiamondTrap " << this->get_Name() << " was created by Dr.Frankenstain" << std::endl;
  
}

DiamondTrap::DiamondTrap( const DiamondTrap & var ) :  ScavTrap( var.get_Name() ), FragTrap( var.get_Name() ){
  this->set_Name(var.get_Name());
  this->set_Hp(var.get_Hp());
  this->set_Dmg(var.get_Dmg());
  this->set_Stamina(var.get_Stamina());
  std::cout << "A shiny new robot made of" << var.get_Name() << "'s parts freshly made comes off the robot distribution line" << std::endl;
  
}


void DiamondTrap::attack( std::string const & name )
{
  this->ScavTrap::attack( name );
}

void DiamondTrap::set_Name( std::string new_name ) {

  this->_name = new_name;
  this->ClapTrap::set_Name(this->get_Name().append("_clap_name"));
}

std::string DiamondTrap::get_Name( void ) const {
  return this->_name;
}

DiamondTrap::~DiamondTrap( void ) {
  
  std::cout << "DiamondTrap got what deserved" << std::endl;

}

void DiamondTrap::whoAmI( void ){
  std::cout << "Ramdom DiamondTrap rises from between the crowd and shouts: " << std::endl;
  std::cout << "Hi i am a robot, yes, but also my name is " << this->get_Name() << std::endl;
  std::cout << "And isnt " << this->ClapTrap::get_Name() << " witch is the one that the humans used to denominate me" << std::endl;
}

DiamondTrap&  DiamondTrap::operator = ( DiamondTrap const &other ){
  this->set_Name(other.get_Name());
  this->set_Hp(other.get_Hp());
  this->set_Dmg(other.get_Dmg());
  this->set_Stamina(other.get_Stamina());
  return *this;
}