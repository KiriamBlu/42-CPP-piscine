
#include "Zombie.hpp"

int	main ( int argc, char **argv ){

	Zombie *macrohorde;

	if ( argc != 2 && isdigit(argv[1]) == 1)
	{
		std::cout << "Too many args" << std::endl;
		return 0; 
	}
	
	int i = std::stoi(  argv[1] );
	macrohorde = zombieHorde(i, "La mama de");
	for ( int x = 0; x < i; x++ )
		macrohorde[x].announce();
	delete [] macrohorde;
}