#include "ClapTrap.hpp"

/*--------------Constructos and destructors-------------*/

ClapTrap::ClapTrap( void ) : _name("Default"),  _healthpoints(10), _energypoints(10), _damage(0){

  std::cout << "Default ClapTrap awoke" << std::endl;
  
}

ClapTrap::ClapTrap( std::string str ) : _name(str), _healthpoints(10), _energypoints(10), _damage(0){

  std::cout << "ClapTrap: " << str << " just became alive" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & var ) : _name(var.get_Name()), _healthpoints(var.get_Hp()), _energypoints(var.get_Stamina()), _damage(var.get_Dmg()){
  std::cout << "A perfect replica of original ClapTrap " <<  var.get_Name() << " has been created" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
  
  std::cout << "ClapTrap imploded" << std::endl;

}

/*----------------------Mandatory----------------------*/

void ClapTrap::attack(std::string const & target)
{
  std::cout << "ClapTrap " << this->get_Name() << " attack " << target << ", causing " << this->get_Dmg() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << "ClapTrap " << this->get_Name() << " took " << amount <<  "points of damage" << std::endl;
  int health_remaining = this->get_Hp() - amount;
  this->set_Hp(health_remaining);
  if (this->get_Hp() < 0)
    this->set_Hp(0);
}

void ClapTrap::beRepaired(unsigned int amount)
{
  std::cout << "ClapTrap " << this->get_Name() << " was repaired by " << amount <<  "points of health" << std::endl;
  this->set_Hp(this->get_Hp() + amount);
}

/*-----------------Getters and setters-----------------*/


std::string ClapTrap::get_Name( void ) const
{
  return(this->_name);
}

int ClapTrap::get_Hp( void ) const
{
  return(this->_healthpoints);
}

int ClapTrap::get_Stamina( void ) const
{
  return(this->_energypoints);
}

int ClapTrap::get_Dmg( void ) const
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

/*------------------Operators----------------------------*/

ClapTrap& ClapTrap::operator = (ClapTrap const &var){
  this->set_Name(var.get_Name());
  this->set_Hp(var.get_Hp());
  this->set_Stamina(var.get_Stamina());
  this->set_Dmg(var.get_Dmg());
  return *this;
}

/*------------------Main utilities----------------------*/

void ClapTrap::announce_hp_left( void )
{
  if(this->get_Hp() > 0)
    std::cout << "ClapTrap " << this->get_Name() << " has " << this->get_Hp() << " left" << std::endl;
  else
    std::cout << "ClapTrap " << this->get_Name() << " is dead" << std::endl;
}



