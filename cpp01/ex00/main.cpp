#include "Zombie.hpp"

int main( void ){

	Zombie aux("joan");
	aux.announce();

	Zombie *lol = new Zombie("Joselito");
	lol->announce();
	delete lol;
	
	randomChump("Manusito");

	Zombie *axixixix = newZombie("Miguelito");
	axixixix->announce();
	delete axixixix;

}