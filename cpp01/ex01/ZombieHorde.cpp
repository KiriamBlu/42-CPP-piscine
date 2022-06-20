
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

	Zombie *newhorde;

	newhorde = NULL;
	if (N <= 0)
		std::cout << "Not able to summon this kind of horde" << std::endl;
	else
	{
		std::string aux;
		newhorde = new Zombie[N];
		for (int x = 0; x < N; x++)
		{
			aux = name + std::to_string( x );
			newhorde[x].setzombiename( aççux );
		}
	}
	return newhorde;
}
