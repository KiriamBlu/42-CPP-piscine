
#include "Zombie.hpp"

int	main ( int argc, char **argv ){

	Zombie *macrohorde;

	if ( argc != 2 )
	{
		std::cout << "Too many args" << std::endl;
		return 0; 
	}
	std::string s( argv[1] );
	int i = std::stoi( s );
	macrohorde = zombieHorde(i, "La mama de");
	for ( int x = 0; x < i; x++ )
		macrohorde[x].announce();
	delete [] macrohorde;
}