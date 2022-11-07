#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main( void ) {
	ClapTrap one("Joselito");
	ClapTrap two("Paco");

	one.attack("a wall");
	one.takeDamage(7);

	one.announce_hp_left();

	one.beRepaired(6);

	one.announce_hp_left();

	two.set_Dmg(9);
	two.attack(one.get_Name());

	one.takeDamage(two.get_Dmg());
	one.announce_hp_left();

	std::cout << std::endl << "/*-------------------------------------------------*/" << std::endl << std::endl;

	two.attack("lava rocks");
	two.takeDamage(8);

	two.announce_hp_left();
	ClapTrap three(two);
	ClapTrap def;
	def = two;
	three.announce_hp_left();
	def.announce_hp_left();

	std::cout << std::endl << "/*-------------------------------------------------*/" << std::endl << std::endl;
	
	ScavTrap	a("JOANSITO");

	a.attack("a wall");
	a.takeDamage(7);

	a.announce_hp_left();

	a.beRepaired(6);

	a.announce_hp_left();

	a.guardGate();	
	a.announce_hp_left();

	std::cout << std::endl << "/*-------------------------------------------------*/" << std::endl << std::endl;

	FragTrap	c("LOKO");

	c.announce_hp_left();

	c.highFivesGuys();

	std::cout << std::endl << "/*-------------------------------------------------*/" << std::endl << std::endl; 

	DiamondTrap		final;
	DiamondTrap 	filled( "RobotronXD" );

	final.attack( "TREE" );
	final.whoAmI();
	final.announce_hp_left();
	final.attack(filled.get_Name());
	filled.takeDamage(final.get_Dmg());
	std::cout << std::endl;
	filled.whoAmI();
	filled.announce_hp_left();
	filled.attack(final.get_Name());
	final.takeDamage(filled.get_Dmg());
	std::cout << std::endl;
	DiamondTrap		copy(filled);
	copy.whoAmI();
	copy.announce_hp_left();
}

